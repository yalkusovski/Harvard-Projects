from cs50 import get_int

while True:
    height = get_int ("Height of Bricks: ")
    if 1 <= height <= 8:
       break

for row in range(1, height + 1):
    print(" " * (height - row) + "#" * row)
