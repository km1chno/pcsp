# Generic Makefile for a C++ project with multiple .cpp and .hpp files

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Source files, header files, and executable name
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
HEADERS := $(wildcard $(INC_DIR)/*.hpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
EXEC = main

# Default target (first one in the file)
all: $(EXEC)

# Linking rule to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilation rule for source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# Automatic dependency generation
DEPS := $(OBJS:.o=.d)
-include $(DEPS)

$(BUILD_DIR)/%.d: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) -I$(INC_DIR) -MM -MT '$(BUILD_DIR)/$*.o' $< > $@

# Clean rule to remove generated files
clean:
	rm -rf $(BUILD_DIR) $(EXEC)

# Phony target to avoid conflicts with files of the same name
.PHONY: all clean

# Prevent make from deleting intermediate files
.SECONDARY:
