/*************************************************************** 
*   USACO
*   Broken Necklace
    Rule:
      A necklace can be broken at any point, collect beads of the same
      color from one end until you reach a bead of different color,
      and do the same for the other end, whic might not be the same
      color as the beads collected before this.  A white bead may be 
      treated as either red or blue.
*   Input file: beads.in
*     r red bead; b blue bead; w white bead
*     line1: N, the number of beads
*     line2: a string of N characters, each of which is r, b, or w
*   Output file: beads.out
*     maximum of number of beads that can be collected with the rule
***************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int next_bead(int, int);
int prev_bead(int, int);

int main()
{

  ifstream beadsin;
  ofstream beadsout;
  int ringlen;
  int beads, maxbeads(0);

  beadsin.open("beads.in");
  beadsin >> ringlen;
  int intlace[ringlen];
  char necklace[ringlen];
  for (int i = 0; i < ringlen; i++)
    beadsin >> necklace[i];
  beadsin.close();

  for (int i = 0; i < ringlen; i++)
    switch(necklace[i]) {
      case 'w': intlace[i] = 0;
                break;
      case 'b': intlace[i] = -1;
                break;
      case 'r': intlace[i] = 1;
    }

  for (int i=0; i<ringlen; i++) {
    beads = 1;
    int j = i;
    while ((intlace[j] == 0) && (beads < ringlen)){
      j = next_bead(j, ringlen);
      beads++;
    }
    int bwcolor = intlace[j];
    j = next_bead(j, ringlen);
    while ((((bwcolor*intlace[j]) > 0) || (intlace[j]==0)) && (beads < ringlen)) {
      j = next_bead(j, ringlen);
      beads++;
    }
    if (beads < ringlen) {
      beads++;
      j = prev_bead(i, ringlen);
      while ((intlace[j] == 0) && (beads < ringlen)) {
        j = prev_bead(j, ringlen);
        beads++;
      }
      bwcolor = intlace[j];
      j = prev_bead(j, ringlen);
      while ((((bwcolor*intlace[j]) > 0) || (intlace[j] == 0)) && (beads < ringlen)) {
        j = prev_bead(j, ringlen);
        beads++;
      }
    }
    if (beads > maxbeads) maxbeads = beads;
  }

  beadsout.open("beads.out");
  beadsout << maxbeads << endl;
  beadsout.close();
  
}


int next_bead(int idx, int ringlen) {
  return ((idx+1)%ringlen);
}

int prev_bead(int idx, int ringlen) {
  return ((idx+ringlen-1)%ringlen);
}
