 #!/bin/bash
 #Copyright (C) 2017 gerry dreamer ventures [Gerishom Muzembi]
 #
 # This program is free software; you can redistribute it and/or
 # modify it under the terms of the GNU General Public License
 # as published by the Free Software Foundation; either version 2
 # of the License, or (at your option) any later version.
 #
 # This program is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 # GNU General Public License for more details.
 #
 # You should have received a copy of the GNU General Public License
 # along with this program; if not, write to the Free Software
 # Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 #
 # contact: gwadunga5@gmail.com
 # For more information/commentary
 #

#compile the files sml.c and main.c
#check if they exist
#first navigate to the containing directory

#show an interactive license

start=$(cat start.txt)
echo $start 
details="w"
continue="c"
read response

license=$(cat license.txt)

if test $response = $details; then
   echo $license
elif test $response = $continue; then
     cd $HOME/Documents/c/sml/
   
#  create variables of the file paths

file1=$HOME/Documents/c/sml/sml.c
file2=$HOME/Documents/c/sml/sml.h
file3=$HOME/Documents/c/sml/main.c

if test -f $file1 && test -f $file2 && test $file3; then
      #echo "file exists"
#run the files
echo "attempting to run files..."
sleep 1 #sleep for one minute
gcc main.c sml.c -o sml
#run the object file via the terminal
./sml
printf "\n%s\n" "program compilation successful"
else
  echo "the files cannnot be found."
fi 
 
fi 


