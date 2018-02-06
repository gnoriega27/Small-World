LIB_SOURCEDIR = lib
LIB_SRC := $(shell find $(LIB_SOURCEDIR) -name '*.cpp')
LIB_OBJ = $(LIB_SRC:.cpp=.o)

APP_SRC = $(LIB_SRC) main.cpp
APP_OBJ = $(APP_SRC:.cpp=.o)

TEST_SRC = $(wildcard tests/*.cpp)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

CXX = g++
LINK = g++

CFLAGS = -lm -lcppunit -Ilib/include -O2 -Wall -Wpedantic -Wextra -Werror -std=c++17
CXXFLAGS = $(CFLAGS)

TARGET = application
TEST_TARGET = testsuite

all: $(TARGET)

$(TARGET): $(APP_OBJ)
	$(LINK) -o $@ $^ $(CXXFLAGS)

runtests: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJ) $(LIB_OBJ)
	$(LINK) -o $@ $^ $(CXXFLAGS)

.cpp:
	$(CXX) -o $@ $@.cpp

SUBDIR_ROOTS := lib tests
CLEAN_DIRS := . $(shell find $(SUBDIR_ROOTS) -type d)
GARBAGE_PATTERNS := *.o .depend *.gch *.orig $(TARGET) $(TEST_TARGET)
GARBAGE := $(foreach DIR,$(CLEAN_DIRS),$(addprefix $(DIR)/,$(GARBAGE_PATTERNS)))

clean:
	rm -rf $(GARBAGE)

format:
	astyle --options=astyle.config --recursive "*.cpp" "*.h"

docs:
	doxygen doc/doxyfile
