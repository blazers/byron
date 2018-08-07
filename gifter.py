"""
ID: emmatli1
LANG: PYTHON2
TASK: gift1
"""

luhan = open('gift.in','r')
kiku = open('gift1.out','w')

guy = int(luhan.readline())
names = dict()

ordname = []

for i in range(0,guy):
  guys = luhan.readline().replace('\n', '')
  names[guys] = 0
  ordname.append(guys)

while True:
    giver = luhan.readline().replace('\n', '')
    if not giver: break
    amount, divide = map(int, luhan.readline().split())
    if divide != 0:
    	rem = amount % divide
    	piece = (amount - rem) // divide
    	for i in range (0, divide):
        	receiver = luhan.readline().replace('\n', '')
        	names[receiver] = names[receiver] + piece
    	names[giver] = (names[giver] - amount) + rem

for y in ordname:
	kiku.write(y)
	kiku.write(str(names[y]))

kiku.close()
