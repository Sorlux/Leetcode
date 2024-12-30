

def main():
    nums = [1,2,3,1]

    # Dictionary to hold unique numbers
    uniqueNumbers = {}

    for number in nums:
        # Return True if the number already exists in the dictrionary
        if number in uniqueNumbers:
            #print("True")
            return True
        uniqueNumbers[number] = 1

    #print("False")
    return False    

main()