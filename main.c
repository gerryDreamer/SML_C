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
#include "sml.h"

 //declare the memory
  int _memory[SIZE];
  
  //declare the instance variables
  int _instrcount = 0;//keeps track of the location in memory that contains the instruction being performed
  int _instrreg = 0;
  int _opcode = 0;
  int _operand = 0;
  int _accum = 0; //represents the accumulator register
  boolean _false = 0; /* false is identified by 0 */
  boolean _true =  1;  /* true is identified by 1 */
  char *_asterisk = "***"; //asterisks used in printing

int main(void)
{
   _init_memory(_memory);/* initialize the memory cells */
  _welcome_message(_asterisk); /* print a welcome message */
  _load_to_memory(_memory);/* load the instructions an data into memory*/
   _load_message(_asterisk);/* */
   _exec_instr(_accum, _instrcount, _instrreg, _opcode, _operand, _memory, _asterisk, _false, _true);/* init the execution cycle */
  // _print_dump(_accum, _instrcount, _instrreg, _opcode, _operand, _memory); /* print the memory dump*/
  // _term_msg(_asterisk);/* terminationMessage */
  return 0;
}
