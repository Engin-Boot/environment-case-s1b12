# Build | Sender 
cd SenderModule

# Generate main_test.o
g++ -c main_test.cpp

# Build CSVReader 
g++ -Wall -Wextra -Werror --coverage -o testchecker CSVReader_test.cpp CSVReader.cpp main_test.o

# Run CSVReader test
./testchecker

# Generate Coverage Report | CSVReader 
gcov -r CSVReader.cpp CSVReader_test.cpp

###################################################################################################################################

# Build Timer
g++ -Wall -Wextra -Werror --coverage -o testchecker Timer_test.cpp Timer.cpp main_test.o

# Run Timer test
./testchecker

# Generate Coverage Report | Timer 
gcov -r Timer.cpp Timer_test.cpp

####################################################################################################################################

# Build Sender
g++ -Wall -Wextra -Werror --coverage -o testchecker THsensor_test.cpp CSVReader.cpp ../Lib/DataProcessingUtility.cpp main_test.o

# Run Sender test
./testchecker

# Generate Coverage Report | Sender
gcov -r THsensor_test.cpp

####################################################################################################################################

# Clean
rm *.gcda *.gcno *.gcov testchecker main_test.o

cd ..

