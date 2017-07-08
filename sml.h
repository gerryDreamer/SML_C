
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


#ifndef SML_H_ /* if not defined, then define */
#define SML_H_ /* define the header */

/*    input output operations  */
  #define SIZE 100//declare the initial size of the array
  #define READ 10
  #define WRITE 11
  #define NEW_LINE 12
  /*   load/store operations  */
  #define LOAD 20
  #define STORE 21
    /*  arithmetic  operations  */
  #define ADD 30
  #define SUBTRACT 31
  #define DIVIDE 32
  #define MULTIPLY 33
  #define REMAINDER 34
  #define EXPONENT 35
    /*  transfer of control operations  */
  #define BRANCH 40
  #define BRANCHNEG 41
  #define BRANCHZERO 42
  #define HALT 43
  
  typedef int boolean; /* create/define a new boolean type */
  
  //boolean _false = 0; /* false is identified by 0 */
  //boolean _true =  1;  /* true is identified by 1 */
  
  int _exponent(int _base, int _exp); /* provides an exponential function capability */
  
 void _exec_instr(int _accum, int _instrcount, int _instrreg, int _opcode, int _operand, int *arrptr, char *_asterisk, boolean _false, boolean _true);//executes all the instructions
 
  int _linear_search(int *arrptr, int x);//linearly searches for an array element
 
  void _load_to_memory(int *arrptr);//load instructions into memory
  
  void _term_msg(char *_asterisk);//terminationMessage
   
  int _set_instrreg();//returns the instr register , int *arrptr, int _instrcount 
  
  int _set_opcode();//returns the current opcode, int _instrreg
  
  int _set_operand();//int _instrreg
  
  void _welcome_message(char *_asterisk);//prints the welcome message
 
  void _load_message(char *_asterisk);//prints the load message
  
  void _init_memory(int *arrptr);//initialize all the memory locations, int *arrptr
  
  void _print_dump(int _accum, int _instrcount, int _instrreg, int _opcode, int _operand, int *arrptr);//print the memory dump, int *arrptr, int _accum, int _operand, int _opcode, int _instrreg, int _instrcount

#endif /* end the header declarations */
