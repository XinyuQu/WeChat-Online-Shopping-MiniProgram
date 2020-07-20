  # the compiler: gcc for C program, define as g++ for C++
CC = g++
  #
  #     # compiler flags:
  #  -g    adds debugging information to the executable file
  #    #  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

  # the build target executable:
TARGET = MyDB
TARGET_TEST = test
  
all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET_TEST).cpp $(TARGET).cpp `mysql_config --clags  --lib`
  
clean:
	$(RM) $(TARGET)
