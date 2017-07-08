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
#alow compilation of the files on a unix like system

#navigate to the home directory

#display the licenses

 license=$(cat license.txt)
 NO="N"
 YES="Y"
 
 echo ""
 echo $license
 echo ""
 
 echo "Do you accept the license terms agreement? "
   echo "Y/N?"
   read response
     
  if test $response = $YES; then
          #continue with compilation
          
_curr_dir=$(pwd) #store a reference to the current directory config is in
echo "current working directory: "$_curr_dir

#create a new directory called c/
cfile=$HOME/Documents/c

  if test -d $cfile; then
        echo $cfile" exists..."       
        cd $cfile
        _final_dir=$cfile
        echo "_final_dir: "$_final_dir
  else
        echo "creating a new directory and opening it..."
        sleep 1
        cd $HOME/Documents
        mkdir c
        cd c 
         _final_dir=$(pwd)
         echo "_final_dir after creation is: "$_final_dir
        ls -a
  fi



cd $_curr_dir #jump to the location of the source files

cd .. #move up one level

cp -r $_curr_dir $_final_dir

cd $_final_dir/sml

echo "file contents..."

sleep 1

ls -a

#check if gcc compiler exists in the system

instr="open your commandline and run the command: 'bash sml.sh' or 'chmod +x sml.sh' then './sml.sh' "

gcc_path=/usr/bin/gcc
gcc_path2=/usr/local/bin/gcc

echo "checking if suitable c compilers are installed: "
sleep 1

if test -f $gcc_path || test -h $gcc_path2; then
  printf "\n gcc compilers found\n"
  gcc -v #print the gcc version information
  #call the shell script for compilation of the program
   #sml_shell=$(cat steps.txt)
   #echo $sml_shell > sml.sh
   mv steps.txt sml.sh
   echo $instr > how_to_run_sml.txt
  else
  echo "no suitable gcc compilers were found. please try installing them" 
fi


  elif test $response = $NO; then
	   echo "Program compilation failed..."
	   echo "program returned with an exit status of 1"
  fi

  
