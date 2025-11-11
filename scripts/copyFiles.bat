echo -Running initial configuration-

set "src=%~1"
set "out=%~2"

echo using %src%
echo and %out%

cd "%src%"

echo step 1

    echo copying library dependencies at
    echo "%src%\lib\"
    xcopy "%src%\lib\sigil-vc2015-win64\lib\*.dll" "%out%\" /y

    echo creating resource folder at
    echo "%src%\res\"
    xcopy "%src%\res\*" "%out%\res\" /y /s /i

    echo creating configs and data
    xcopy "%src%\config\*" "%out%\config\" /y /s /i
    xcopy "%src%\data\*"   "%out%\data\"   /y /s /i

echo Done!
