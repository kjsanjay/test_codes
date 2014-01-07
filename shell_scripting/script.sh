#!/bin/bash
# Purpose:   Inserts #!/bin/bash into a file and makes it executable
# Usage:    scriptname /path/to/file.sh
# Author:    JJ/Habitual
# Date:    Tue Jul 19, 2011
# Version:    1311133977
# Disclaimer:   Use it, abuse it, just don't lose it.
MINPARAMS=1

if [ -n "$1" ]
then
echo "#!/bin/bash" > $1
chmod 700 "$1"
echo File $1 is now an executable and ready to be edited.
fi 

if [ $# -lt "$MINPARAMS" ]
then
  echo Usage: `basename $0` script.sh
fi  
exit 0
