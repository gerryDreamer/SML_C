

/*
 * Copyright (C) 2017 gerry dreamer ventures [Gerishom Muzembi]
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * contact: gwadunga5@gmail.com
 * For more information/commentary
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "sml.h"


void _exec_instr(int _accum, int _instrcount, int _instrreg, int _opcode, int _operand, int *arrptr, char *_asterisk,boolean _false, boolean _true)
{
  boolean _done = _false;//set done to a false value
  int _init_count = 0;//the initial value of the instructionCounter
  int _curr_count = 0;//the final value of the instructionCounter
  
  int _end_index = _linear_search(arrptr,4300);
  //printf("end index: %d\n",_end_index);
  /* loop thru the instructions until the end instruction is reached  */
  do
    {
   //   printf("instr: %d\n",*(arrptr + _instrcount));
     // ++_instrcount;
     _instrreg = arrptr[_instrcount];//the register points to the current array element
     _opcode = _instrreg/100;
     _operand = _instrreg%100;
    // printf("reg: %d opcode: %d operand:%d\n",_instrreg,_opcode, _operand);
   
    switch(_opcode)
    {
      case READ:
        printf("please enter an integer: ");
        scanf("%d",(arrptr + _operand));//modify a specific array index
      break;
      
      case WRITE:
      putchar('\n');
      puts("*** stdout ***");
         printf("%d\n",*(arrptr + _operand));
          puts("*** stdout ***");
          putchar('\n');
        // printf("%d\n",arrptr[_operand]);
      break;
      
      case LOAD:
        _accum = *(arrptr + _operand);
      break;
      
      case STORE:
      *(arrptr + _operand) = _accum;//retrieve the value from the accumulator
      break;
      
      case ADD:
         _accum += *(arrptr + _operand);
      break;
      
      case SUBTRACT:
         _accum -= *(arrptr + _operand);
      break;
      
      case DIVIDE:
         _accum /= *(arrptr + _operand);
      break;
      
      case MULTIPLY:
          _accum *= *(arrptr + _operand);
      break;
      
      case BRANCH:
         //manipulate the branching operations
         printf("initial counter: %d\n", _instrcount);
         _init_count = _instrcount;
         _curr_count = _instrcount + 1;
         /* begin branch operation*/
         _instrcount = _operand;
          /* end branch operation*/
         printf("_init_count: %d\n", _init_count);
          printf("_curr_count: %d\n", _curr_count);
           printf("_instrcount: %d\n", _instrcount);
         puts("branching...");
         printf("final counter: %d\n",_instrcount);
         _done = _true;
      break;
      
      case BRANCHNEG:
         //manipulate the branching operations
         printf("initial counter: %d\n", _instrcount);
         _init_count = _instrcount;
         _curr_count = _instrcount + 1;
         /* begin branchneg operation*/
         if(_accum < 0)
           {
            _instrcount = _operand;
            //la commence
             printf("_init_count: %d\n", _init_count);
          printf("_curr_count: %d\n", _curr_count);
           printf("_instrcount: %d\n", _instrcount);
         puts("branching negatives...");
         printf("final counter: %d\n",_instrcount);
         _done = _true;
           }
          /* end branchneg operation*/
        
      break;
      
      case BRANCHZERO:
               //manipulate the branching operations
         printf("initial counter: %d\n", _instrcount);
         _init_count = _instrcount;
         _curr_count = _instrcount + 1;
         /* begin branchzero operation*/
         if(_accum == 0)
           {
            _instrcount = _operand;
            //la commence
             printf("_init_count: %d\n", _init_count);
          printf("_curr_count: %d\n", _curr_count);
           printf("_instrcount: %d\n", _instrcount);
         puts("branching zeros...");
         printf("final counter: %d\n",_instrcount);
         _done = _true;
           }//end if
          /* end branchzero operation*/        
      break;
      
      case REMAINDER:
          _accum %= *(arrptr + _operand);
      break;
      
      case EXPONENT:
           //find the exponent
           _accum = _exponent(_accum,*(arrptr + _operand));
      break;
      
      case NEW_LINE:
          putchar('\n');//output a newline to stdout
      break;
      
      case HALT:
      _term_msg(_asterisk);
       _print_dump(_accum, _instrcount, _instrreg, _opcode, _operand, arrptr); /* print the memory dump*/
      break;
    }//end switch  
    
    //increment the counter
    if(_opcode != BRANCH && _opcode != BRANCHNEG && _opcode != BRANCHZERO)
    {
	      if(_done == _false)
	      {
	       ++_instrcount;
	      }//end if _done -eq _false
              
             else if(_done == _true)
              {
                  if(_curr_count == _end_index)
                    {
                    //do nothing if the next instruction is halt
                     // _instrcount = _curr_count;
                      _instrcount = _end_index;/* let the _instrcount be the final index now */
                      _done = _false;/* set _done to _false to allow for incrementation */                    
                    }//end inner if
                    else
                    {
                      //increment the counter
                      _instrcount = _init_count + 1;
                      _done = _false;
                    }//end inner else
              }//end else  */
    }//end if
   }//end do
  while(_instrcount <= _end_index);  
}

  /* create a linear search array algorithm */
  int _linear_search(int *arrptr, int x)
  {
    int i=0;
	for(; i< SIZE; i++)
	{
	 if(*(arrptr + i) == x)
	{
	  return i;
	}//end if
	}
return -1;
  }

//expand on the function prototypes
void _load_to_memory(int *arrptr)
{
  //load the instructions into memory
 int _sentinel = -99999;
 int i=0;
  int _word = 0;
  do
  {
    printf("%-s%02d ? ","",i);
    scanf("%d",&_word);// receive input from stdin
    //add the word to the array if it is not the sentinel
    if(_word != _sentinel)
      {
      *(arrptr + i) = _word;//let the new word reference the array based in the index i
      }
    i++;
  }
  while(_word != _sentinel);
}

void _term_msg(char *_asterisk)
{
 printf("\n\n%s %s %s\n\n",_asterisk,"Simpletron execution terminated", _asterisk);
}

//define the print dump method
void _print_dump(int _accum, int _instrcount, int _instrreg, int _opcode, int _operand, int *arrptr)
 {
 //print the headers
   printf("\n%s\n","REGISTERS:");
   if(_accum >= 0)
   printf("%-30s%-s%04d\n","accumulator","+",_accum);
     else
    printf("%-30s%4d\n","accumulator",_accum);  
      
     printf("%-30s%02d\n","instruction_counter",_instrcount);
     
     if(_instrreg >= 0)
       printf("%-30s%-s%04d\n","instruction_register","+",_instrreg);
       else
        printf("%-30s%02d\n","instruction_register",_instrreg);
         printf("%-30s%02d\n","operation_code",_opcode);
           printf("%-30s%02d\n","operand",_operand);
           
           //now print the memory
           printf("\nMEMORY:\n");
           
       //print number headers 
       int i=0;
       for(; i<(SIZE/10); i++)
       printf("%-6d",i);  
       printf("\n");//create a new line
       i = 0;
       int j=0;
        for(; i<SIZE; i++)
       {        
           //print a newline after 10 memory cells
          if(i%(SIZE/10)==0)
          {
          if(i>0)
           printf("%d \n",j*10);
          j++;  
          }          
         
         //print the memory cells
          int val = *(arrptr + i);          
          if(val>= 0)
            {
                char *_sign1 = "+";/* create a string representation of the plus sign*/
                printf("%-s%04d ",_sign1,val); //if this is a positive value
            }
          else
             {
              int temp = abs(val);//find the abs val of the element
              char *_sign = "-"; /* create a string representation of the minus sign*/             
              printf("%-s%04d",_sign,temp);       
             }  //if this is a negative value  
           
       }
         
 }//end _print_dump

void _load_message(char *_asterisk)
{
 printf("%s %s %s\n",_asterisk,"Program loading completed",_asterisk);  
  printf("%s %s %s\n",_asterisk,"Program execution begins",_asterisk);  
}

void _welcome_message(char *_asterisk)
 {   
    printf("%s %s %s\n",_asterisk,"Welcome to simpletron!",_asterisk);
     printf("%s %s %s\n",_asterisk,"Please enter your program one instruction",_asterisk);
      printf("%s %s %s\n",_asterisk,"(or data word) at a time. I will type the ",_asterisk);
       printf("%s %s %s\n",_asterisk,"location number and a question mark (?)",_asterisk);
        printf("%s %s %s\n",_asterisk,"You then type the word for that location",_asterisk);
         printf("%s %s %s\n",_asterisk,"Type the sentinel -99999 to stop entering ",_asterisk);
          printf("%s %s %s\n",_asterisk,"your program.",_asterisk);
         //  printf("%s %s %s",asterisk,"",asterisk);
 } 
 
 //initialize the memory to zeros
 
 void _init_memory(int *arrptr)
 {
 int i=0;
   for(; i<SIZE; i++)
   {
     *(arrptr + i) = 0;//set every memory cell to a default value of 0
   }
 }//end _init_memory
 
 int _exponent(int _base, int _exp)
{
  if(_exp == 1)
    return _base;
  else
    return _base * _exponent(_base, _exp-1);
}
 
