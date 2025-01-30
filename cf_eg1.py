import my_module
import cf
from numpy.testing import assert_almost_equal

# Read some data
a = cf.read('../ECMWF_ERA-40_subset.nc')

# Test our subroutine for a 1D slice
# Pick data with no masking

original_numbers1 = a[8].array[0,2:4,2].data
result_array1     = my_module.read_numpy_array(original_numbers1)

assert_almost_equal(original_numbers1 * 2.,
                    result_array1)

print(original_numbers1)
print(result_array1)

# Test our subroutine for a 2D slice
# Pick data with no masking

original_numbers2 = a[8].array[0,2:4,2:4].data
result_array2     = my_module.read_numpy_array(original_numbers2)

assert_almost_equal(original_numbers2 * 2.,
                    result_array2)

print(original_numbers2)
print(result_array2)
