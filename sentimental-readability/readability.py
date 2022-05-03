import re
from cs50 import get_string
import string

letters = 0
words = 1
sentences = 0

text = get_string("Text: ")

for char in text:

    if char == '!' or char == '?' or char == '.':
        sentences += 1
    if char in string.punctuation:
        continue
    if char in string.whitespace:
        words += 1
    else:
        letters += 1

index = round((0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8)

if index > 16:
    print("Grade 16+")

if index < 1:
    print("Before Grade 1")

else:
    print(f"Grade {index}")
