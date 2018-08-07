"""
USACO Friday 13th
Jan 1, 1900 is a Monday
Input: n as years since 1900
Output: total number of Saturday, Sunday, ... 13th falls on
"""

#!/usr/bin/python

inf = open('friday.in', 'r')
ouf = open('friday.out','w')

val = int(inf.readline())

days = [0]*(val*365)
for i in range(val*365): days[i] = i%7

week = [0]*7
carry = 0
offset = 0
mon13 = [0]*12

for x in range(val):
  year = x + 1900
  offset = offset+carry
  if (year%4 == 0): Feb = 29
  else: Feb = 28
  if (year%100 == 0): Feb = 28
  if (year%400 == 0): Feb = 29
  mon13[0]  = days[offset+12]
  mon13[1]  = days[offset+31+12]
  mon13[2]  = days[offset+31+Feb+12]
  mon13[3]  = days[offset+31+Feb+31+12]
  mon13[4]  = days[offset+31+Feb+31+30+12]
  mon13[5]  = days[offset+31+Feb+31+30+31+12]
  mon13[6]  = days[offset+31+Feb+31+30+31+30+12]
  mon13[7]  = days[offset+31+Feb+31+30+31+30+31+12]
  mon13[8]  = days[offset+31+Feb+31+30+31+30+31+31+12]
  mon13[9]  = days[offset+31+Feb+31+30+31+30+31+31+30+12]
  mon13[10] = days[offset+31+Feb+31+30+31+30+31+31+30+31+12]
  mon13[11] = days[offset+31+Feb+31+30+31+30+31+31+30+31+30+12]
  carry = 31+Feb+31+30+31+30+31+31+30+31+30+31

  for i in range(12): week[mon13[i]] = week[mon13[i]] + 1

for weekday in range(7):
  ouf.write(str(week[(weekday+5)%7]))
  ouf.write(" ")

inf.close()
ouf.close()
