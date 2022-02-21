from cs50 import get_string


text = get_string("Text: ")
letters = sentences = words = n = 0
length = len(text)


while n < length:

#Letter count

    if text[n].isalpha():
        words += 1

#word count

    if (n == 0 and text[n] != " ") or (n != length and text[n] == " " and text[n + 1] != " "):
        letters += 1
    if text[n] == "." or text[n] == "?" or text[n] == "!":
        sentences += 1
    n += 1


L = (words / letters) * 100
S = (sentences / letters) * 100
solution = int((0.0588 * L - 0.296 * S - 15.8) + 0.5)


if solution < 1:
    print("Before Grade 1")
elif solution >= 16:
    print("Grade 16+")
else:
    print(f"Grade {solution}")
