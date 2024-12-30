# More efficient wy to do this is using Counter from collections

def main():
    s = "anagram"
    t = "nagaram"

    sDict = {}
    tDict = {}
    uniqueCharacters = []

    # Quick check to make sure the length match up
    if len(s) != len(t):
        return False
    
    # Counting all characters in s and appending unique characters to a separate list
    for character in s:
        if character not in sDict:
            sDict[character] = 0
            uniqueCharacters.append(character)
        sDict[character] += 1
        
    # Counting all characer in t
    for character in t:
        tDict[character] = tDict.get(character,0) + 1

    # Making sure that the counts for each character line up
    for character in uniqueCharacters:
        if sDict[character] != tDict.get(character,0):
            print("false")
            return False
    
    print("true")
    return True

main()