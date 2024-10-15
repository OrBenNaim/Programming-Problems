from functions import *

def test_max_subArray_sum():
    array = [2, 3, -8, 7, -1, 2, 3]
    print("\n--------------------- Find Maximum Subarray Sum Problem ---------------------")
    print(f"The maximum sum from all the subarrays is: {max_subArray_sum(array)}\n")



def test_find_missing_number():
    array = [2, 3, -8, 7, -1, 2, 3]
    print("\n--------------------- Find Maximum Subarray Sum Problem ---------------------")
    print(f"The maximum sum from all the subarrays is: {max_subArray_sum(array)}\n")


def test_trapping_rain_water():
    print("\n--------------------- Find the Missing Number Problem ---------------------")
    array = [1, 2, 3, 5]
    n = 5
    print(f"The missing number is: {find_missing_number(array, n)}\n")

    arr2 = [3, 0, 2, 0, 4]
    print(f"\nThe amount of water in arr2 is: {trapping_rain_water(arr2)}\n")

    arr3 = [1, 2, 3, 4]
    print(f"\nThe amount of water in arr3 is: {trapping_rain_water(arr3)}\n")

    arr4 = [10, 9, 0, 5]
    print(f"\nThe amount of water in arr4 is: {trapping_rain_water(arr4)}\n")



def test_max_product_subarray():
    print("\n--------------------- Maximum Product Subarray Problem ---------------------")
    arr1 = [-2, 6, -3, -10, 0, 2]
    print(f"The max product subarray of arr1 is: {max_product_subarray(arr1)}\n")

    arr2 = [-1, -3, -10, 0, 60]
    print(f"The max product subarray of arr2 is: {max_product_subarray(arr2)}\n")


def test_find_leaders():
    print("\n--------------------- Leaders in an array Problem ---------------------")
    arr = [16, 17, 4, 3, 5, 2]
    find_leaders(arr)