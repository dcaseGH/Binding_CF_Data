CXX = c++
CXXFLAGS = -shared -fPIC -I${CONDA_PREFIX}/include -I${CONDA_PREFIX}/include/python3.12 -L${CONDA_PREFIX}/lib
output_suffix = $(shell python3-config --extension-suffix)
#output_suffix = cpython-312-x86_64-linux-gnu.so

my_module$(output_suffix): my_module.cpp
	$(CXX) -o $@ $< $(CXXFLAGS)
