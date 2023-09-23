def reverseWords(s):
    words = s.split()
    reversed_words = words[::-1]
    print(reversed_words)
    reversed_string = ' '.join(reversed_words)
    return reversed_string

def reverseString(s):
    return s[::-1]

s = "I SAW A CAT"
x = reverseWords(s)
y = reverseString(s)
print(x)
print(y)
