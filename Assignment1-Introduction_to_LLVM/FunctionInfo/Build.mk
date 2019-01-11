OPTIMIZER := FunctionInfo.so

LLVM_VERSION := 6.0

CXXFLAGS := $(shell llvm-config-$(LLVM_VERSION) --cxxflags) -rdynamic -g -std=c++17

OPT_OBJs := $(subst .cpp,.o,$(wildcard *.cpp))

all: $(OPTIMIZER) 

# Build the optimizer from the source files.
$(OPTIMIZER): $(OPT_OBJs)
	$(CXX) -dylib -shared $^ -o $@
.INTERMEDIATE: $(OPT_OBJs) # Mark object files as intermediate targets.

.PHONY: clean
clean:
	$(RM) $(OPTIMIZER)