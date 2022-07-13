import sys
s = ""
while s != 'quit':
    s = input('gimmmi some input baby: ')
    if s == "":
        print("alright, im outta here")
        sys.exit()
    if s == s[::-1] and s != " ":
        print("i'm a palindrome")
    else:
        print(f"it's not looking good, {s} looks nothing like {s[::-1]}.")