ALPHABET = ['a','b','c']

compDict = {}
decompDict = {}

# str: a string consisting of characters in the alphabet.
def compr(text):
    code = []
    for letter in ALPHABET:
        compDict[letter] = len(compDict) + 1 # a->1, b->2 etc
    word = ""
    for letter in text:
        if (word+letter) in compDict:
            word = word+letter
        else:
            compDict[word+letter] = len(compDict) + 1
            code.append( compDict[word] )
            word = letter
    code.append( compDict[word] )
    return code


def decompr(code):
    text = ""
    for letter in ALPHABET:
        decompDict[len(decompDict) + 1] = letter # 1->a, 2->b etc

    prev = decompDict[ code[0] ]
    text += prev
    for num in code[1:]:
        if num in decompDict:
            text += decompDict[num]
            decompDict[len(decompDict) + 1] = prev + decompDict[num][0] # 

        else: #special case
            text += prev + prev[0]
            decompDict[len(decompDict) + 1] = prev + prev[0]

        prev = decompDict[num]

    return text


# compressed = compr("abcab")
inputStr = "ababcbababaaaa"
compressed = compr(inputStr)
print(compressed)
decompressed = decompr(compressed)
print(decompressed)
print( inputStr == decompressed)