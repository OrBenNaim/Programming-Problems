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


if __name__ == "__main__":
    
    #---------------------- Test Maximum Subarray Sum problem ---------------------- 
    array = [2, 3, -8, 7, -1, 2, 3]
    print(f"\nThe maximum sum from all the subarrays is: {max_subArray_sum(array)}\n")


    #---------------------- Test Find the Missing Number problem ---------------------- 
    array = [1, 2, 3, 5]
    n = 5
    print(f"\nThe missing number is: {find_missing_number(array, n)}\n")
