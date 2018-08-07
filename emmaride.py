'''
your ride is here with UFO
'''

def lucky(word):
  total = 1
  for i in range(0, len(word)):
    total = total * (ord(word[i]) - ord('A') + 1)
  hashval = total % 47
  return hashval

with open('ride.in', 'r') as owo:
	comet = owo.readline().strip()
	group = owo.readline().strip()

with open('ride.out', 'w') as uwu:
  if lucky(comet) == lucky(group): 
    uwu.write("GO\n")
  else: 
    uwu.write("STAY\n")
