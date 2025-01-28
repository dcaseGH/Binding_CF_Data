#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

// Templating may help - eg for masked arrays
template <typename T>

py::array_t<double> read_numpy_array(const py::array_t<double> &input_array) {
  // Check if the input array is contiguous in memory
  //assume old and will be c_contiguous?
  /*   if (!input_array.flags() & py::array::c_contiguous) {
      throw std::runtime_error("Input array must be C-contiguous");
    }
  */
  // Get the dimensions of the input array
  py::buffer_info info = input_array.request();

  if (info.ndim == 1)
  {
    size_t num_elements = info.shape[0]; 
  
    // Create a new output array with the same dimensions
    py::array_t<double> output_array(num_elements);

    // Get pointers to the data of the input and output arrays
    double *input_data  = static_cast<double *>(info.ptr);
    double *output_data = output_array.mutable_data();

    // Perform some operations on the data (example: copy the input array)
    for (size_t i = 0; i < num_elements; ++i) {
            output_data[i] = 2.0 * input_data[i]; 
	    //		*(double*)(buf_result.ptr + i * buf_result.strides[0] + 
            //     j * buf_result.strides[1]) = *(double*)(info.ptr + i * info.strides[0] + 
							 j * info.strides[1]) * 2.;

    }
    return output_array;
  }
  else if (info.ndim == 2)
  {
    // matrix version
    size_t num_i = info.shape[0]; 
    size_t num_j = info.shape[1]; 

    py::array_t<double> output_array = 
      py::array_t<double>({info.shape[0], info.shape[1]});
    py::buffer_info buf_result = output_array.request();

    for (size_t i = 0; i < num_i; ++i) {
      for (size_t j = 0; j < num_j; ++j) {
         
		*(double*)(buf_result.ptr + i * buf_result.strides[0] + 
                 j * buf_result.strides[1]) = *(double*)(info.ptr + i * info.strides[0] + 
							 j * info.strides[1]) * 2.;
      }
    }
    return output_array;
  }
  else
  {
      throw std::runtime_error("Give us an array or matrix");
  }
}

// Be sure to give all possible arguments that the template can take as defs
// If it were just a function then wouldn't need to give the argument types
PYBIND11_MODULE(my_module, m) {
  m.doc() = "pybind11 example module";
  m.def("read_numpy_array", &read_numpy_array<py::array_t<double>>, "Read a numpy array");
}
