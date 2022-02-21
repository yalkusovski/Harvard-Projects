from cs50 import get_float

# coin counter
coins = 0
#in a loot promnt user for change owed. Re-promnts if give invalid value
while True:
    coins_owed = get_float("Change owed: ")
    if coins_owed > 0:
        break

#rounds up coints
cent  = round(coins_owed * 100)


while cent >= 25:
    cent = cent - 25
    coins += 1


while cent >= 10:
    cent = cent - 10
    coins += 1


while cent >= 5:
    cent = cent - 5
    coins += 1


while cent >=1:
    cent = cent - 1
    coins += 1

#prints coins
print(coins)