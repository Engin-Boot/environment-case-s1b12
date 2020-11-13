# Static Analysis | Sender
cppcheck --enable=all --error-exitcode=1 --suppress=missingIncludeSystem --suppress='*:Lib/catch*' SenderModule/CSVReader_test.cpp SenderModule/CSVReader.cpp SenderModule/Timer.cpp SenderModule/THsensor_test.cpp
cppcheck --enable=all --error-exitcode=1 --suppress=missingIncludeSystem ReceiverModule/*.cpp receiver.cpp
