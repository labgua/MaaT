IDIR=src
INCLUDE=include
DIRCONFIG_FILE=$(dirname "${BASH_SOURCE[0]}")

echo "Coping all sources files in 'src' path..."
echo "find $DIRCONFIG_FILE/../ -maxdepth 2 -iname "*.cpp" -exec cp {} $DIRCONFIG_FILE/$IDIR/ \;"
find $DIRCONFIG_FILE/../ -maxdepth 2 -iname "*.cpp" -exec cp {} $DIRCONFIG_FILE/$IDIR/ \;

echo "Coping all include files in 'include' path..."
echo "find $DIRCONFIG_FILE/../ -maxdepth 2 -iname "*.h" -exec cp {} $DIRCONFIG_FILE/$INCLUDE/ \;"
find $DIRCONFIG_FILE/../ -maxdepth 2 -iname "*.h" -exec cp {} $DIRCONFIG_FILE/$INCLUDE/ \;

echo "Removing module and main from src..."
echo "rm $IDIR/module.cpp $IDIR/main.cpp $INCLUDE/module.h"
rm $IDIR/module.cpp $IDIR/main.cpp $INCLUDE/module.h