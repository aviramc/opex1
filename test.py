import os
import itertools

k_template = """#define SUB_ARRAYS (%d)        /* The 'k' of the exercise */"""
build_command = "./build.sh"

inputs = ["input_no_order", "input_sorted", "input_sorted_reverse"]
k_values = range(1, 256)

def run_test(k, input_array):
    open("subarray.h", 'wt').write(k_template % k)
    os.system(build_command)
    os.system("./ex14 %s > %s_%d" % (input_array, input_array, k))

for input_array, k in itertools.product(inputs, k_values):
    run_test(k, input_array)
    
              
    
