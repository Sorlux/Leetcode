from typing import List


def maxArea(height:List[int]):
    maxValue = 0

    leftPointer = 0
    rightPointer = len(height) - 1

    while leftPointer < rightPointer:
        if height[leftPointer] < height[rightPointer]:
            area = height[leftPointer] * (rightPointer - leftPointer)
            leftPointer+=1
        else:
            area = height[rightPointer] * (rightPointer - leftPointer)
            rightPointer-=1
        
        if area> maxValue:
            maxValue = area


    return maxValue

def main():
    height = [1,8,6,2,5,4,8,3,7]

    print(maxArea(height))



if __name__ == "__main__":
    main()
