# Name of the project
PROJECT_NAME = Hangman

# Output directory
BUILD = build

# All source code files
SRC = main.c\
src/hangman.c

# All test source files
TEST_SRC = src/hangman_operations.c\
test/test_hangman_operations.c\
unity/unity.c\

# All include folders with header files
INC	= -Iinc\
-Iunity\

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME).$(EXEC)

# Project Output name
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).$(EXEC)

# Document files
DOCUMENTATION_OUTPUT = documentation/html

# Default target built
$(PROJECT_NAME):all

# Run the target even if the matching name exists
.PHONY: run clean test doc all

all: $(SRC) $(BUILD)
	gcc $(SRC) $(INC) -o $(PROJECT_OUTPUT)

# Call `make run` to run the application
run:$(PROJECT_NAME)
	./$(PROJECT_OUTPUT)

# Document the code using Doxygen
doc:
	make -C doc
$(BUILD):
	mkdir $(BUILD)

# Build and run the unit tests
test:$(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)
#Coverage
coverageCheck:$(PROJECT_NAME)
	gcc -fprofile-arcs -ftest-coverage $(TEST_SRC) $(INC) -o $(call FixPath,$(TEST_OUTPUT))
	$(call FixPath,$(TEST_OUTPUT))
	gcov -a hangman_operations.c

# Remove all the built files, invoke by `make clean`
clean:
	$(RM) $(call FixPath,$(BUILD)/*)
	make clean -C doc
	rmdir $(BUILD) doc/html

# Create new build folder if not present
$(BUILD):
	mkdir build
