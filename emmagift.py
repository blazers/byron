#!/usr/bin/python

infile = open('gift.in','r')

guys = int(infile.readline())
names = dict()
for idx in range(0,guys):
  guy = infile.readline()
  names[guy] = 0

for line in infile:
    giver = input()
    amount, divide = map(int, input().split())
    if (divide == 0):
        break;
    piece = amount // divide
    for idx in range (0, divide):
        receiver = input()
        names[receiver] = names[receiver] + piece
    names[giver] = names[giver] - piece * divide
for keys,values in names.items():
    print(keys, values)
