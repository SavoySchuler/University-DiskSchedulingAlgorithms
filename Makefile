# GNU C/C++ compiler and linker:
CPP = g++

# Preprocessor and compiler flags
CXXFLAGS = $(CFLAGS) -std=c++11

# Targets
TARGET = disk_sched

#Build Everything

all: $(TARGET)

#Dependencies 
$(TARGET): disk_sched.o
	$(CPP) $(CFLAGS) -o $@ $^

#Include option for clean sweep of objects and executables
clean:
	rm -f *.o *~ core $(TARGET)



