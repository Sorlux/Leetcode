from typing import List


# Strategy: Area is dependent on the lowest of the two values at the chosen indices.
# Therefore if we move the pointer at the lowest value, we have the chance to increase the max area

def maxArea(height:List[int]):
    maxValue = 0

    leftPointer = 0
    rightPointer = len(height) - 1

    # Checking every potential value inbetween two pointers
    while leftPointer < rightPointer:

        # Calculating area and deciding whether to move the leftpointer or rightpointer based on which is smaller
        if height[leftPointer] < height[rightPointer]:
            area = height[leftPointer] * (rightPointer - leftPointer)
            leftPointer+=1
        else:
            area = height[rightPointer] * (rightPointer - leftPointer)
            rightPointer-=1

        
        if area > maxValue:
            maxValue = area


    return maxValue

def main():
    height = [1,8,6,2,5,4,8,3,7]

    print(maxArea(height))



if __name__ == "__main__":
    main()
