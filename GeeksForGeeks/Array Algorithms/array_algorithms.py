# https://www.geeksforgeeks.org/top-10-algorithms-in-interview-questions/#1-array

from typing import List

def max_subArray_sum(arr: List[int]) -> int:
    res = arr[0]
    maxEnding = arr[0]

    for i in range(1, len(arr)):
        maxEnding = max(maxEnding + arr[i], arr[i])
        res = max(res, maxEnding)
    
    return res


def find_missing_number(arr: List[int], N: int) -> int:
    realSum = sum(arr)  
    arithmeticSum = (N * (1+N)) // 2
    return arithmeticSum - realSum


def trapping_rain_water(arr: int) -> int:
    cnt = start = remove = 0 
    end = 1

    if len(arr) <= 2: 
        return 0
    
    while end < len(arr):
        if (arr[start] == 0):
            start += 1
        
        elif (end - start == 1 and arr[end] != 0):
            start += 1
        
        elif (end - start != 1):
            
            if (arr[end] >= arr[start]):
                cnt += arr[start] * (end - (start + 1)) - remove
                start = end
                remove = 0
            
            else:
                remove += arr[end]
        
        end += 1
    
    cnt += remove   # For cases that there is no arr[end] >= arr[start]

    return cnt


def max_product_subarray(arr: int) -> int:
    if len(arr) == 0:
        raise Exception("Empty array\n")
    
    currMax = currMin = maxPro = arr[0]
    n = len(arr)

    for i in range(1, n):
        temp = max(currMin * arr[i], currMax * arr[i], arr[i])
        currMin = min(currMin * arr[i], currMax * arr[i], arr[i])
        currMax = temp
        maxPro = max(currMax, maxPro)
    
    return maxPro
    

if __name__ == "__main__":
    
    #---------------------- Test Find Maximum Subarray Sum Problem ---------------------- 
    array = [2, 3, -8, 7, -1, 2, 3]
    print("\n--------------------- Find Maximum Subarray Sum Problem ---------------------")
    print(f"The maximum sum from all the subarrays is: {max_subArray_sum(array)}\n")


    #---------------------- Test Find the Missing Number Problem ---------------------- 
    print("\n--------------------- Find the Missing Number Problem ---------------------")
    array = [1, 2, 3, 5]
    n = 5
    print(f"The missing number is: {find_missing_number(array, n)}\n")


    #---------------------- Test Trapping Rain Water Problem ---------------------- 
    print("\n--------------------- Trapping Rain Water Problem ---------------------")
    arr1 = [3, 0, 1, 0, 4, 0, 2]
    print(f"The amount of water in arr1 is: {trapping_rain_water(arr1)}\n")

    arr2 = [3, 0, 2, 0, 4]
    print(f"\nThe amount of water in arr2 is: {trapping_rain_water(arr2)}\n")

    arr3 = [1, 2, 3, 4]
    print(f"\nThe amount of water in arr3 is: {trapping_rain_water(arr3)}\n")

    arr4 = [10, 9, 0, 5]
    print(f"\nThe amount of water in arr4 is: {trapping_rain_water(arr4)}\n")


    #---------------------- Test Maximum Product Subarray Problem ----------------------
    print("\n--------------------- Maximum Product Subarray Problem ---------------------")
    arr1 = [-2, 6, -3, -10, 0, 2]
    print(f"The max product subarray of arr1 is: {max_product_subarray(arr1)}\n")

    arr2 = [-1, -3, -10, 0, 60]
    print(f"The max product subarray of arr2 is: {max_product_subarray(arr2)}\n")
    