SET include=%cd%\include
SET binary=%cd%\bin
SET source=%cd%\src

g++ %source%\main.cpp -o %binary%\main -I%include% %include%\ItemTracker.cpp