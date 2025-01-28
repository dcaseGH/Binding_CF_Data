import my_module
import cf
from numpy.testing import assert_almost_equal

# Read some data
a = cf.read('../ECMWF_ERA-40_subset.nc')

# Test our subroutine for a 1D slice
# Pick data with no masking

original_numbers = a[8].array[0,2:4,2].data
result_array     = my_module.read_numpy_array(original_numbers)

#assert_almost_equal(original_numbers * 2.,
#                    result_array)

print(original_numbers)
print(result_array)

# Test our subroutine for a 2D slice
# Pick data with no masking

original_numbers = a[8].array[0,2:4,2:4].data
result_array     = my_module.read_numpy_array(original_numbers)

assert_almost_equal(original_numbers * 2.,
                    result_array)

print(original_numbers)
print(result_array)
