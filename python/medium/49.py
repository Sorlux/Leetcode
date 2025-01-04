from typing import List

def groupAnagrams(strs: List[str]):

    # If two words are identical when sorted, then this means that they are anagrams
    # Therefore, create a dictionary which will hold unique sorted words as keys and then the actual words as the values
    uniqueAnagrams = {}


    
    for word in strs:
        # Sorting each individual word
        # sorted returns a list of characters so we need to use .join to combine it back into a string
        key = ''.join(sorted(word))

        if key not in uniqueAnagrams:
            uniqueAnagrams[key] = []

        uniqueAnagrams[key].append(word)



    return list(uniqueAnagrams.values())

def main():

    strs = ["eat","tea", "tan", "ate", "nat", "bat"]


    print(groupAnagrams(strs))


if __name__ == "__main__":
    main()