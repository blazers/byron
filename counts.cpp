#include <iostream>
using namespace std;

int next_bead(int);
int prev_bead(int);

int main()
{
  char necklace[] = "wwwbbrwrbrbrrbrbrwrwwrbwrwrrb";
  int intlace[29];
  int beads, maxbeads(0);

  for (int i = 0; i < 29; i++) {
    if (necklace[i] == 'w') intlace[i] = 0;
    if (necklace[i] == 'b') intlace[i] = -1;
    if (necklace[i] == 'r') intlace[i] = 1;
  }

  for (int i = 0; i< 29; i++) cout << necklace[i];
  cout << endl;
  for (int i = 0; i< 29; i++) cout << intlace[i];
  cout << endl;

  for (int i=0; i<29; i++) {
    beads = 0;
    int j = i;
    while (intlace[j] == 0) {
      j = next_bead(j);
      beads++;
    }
    cout << "tp1\n";
    int bwcolor = intlace[j];
    j = next_bead(j);
    while (((bwcolor*intlace[j]) > 0) or (intlace[j]==0)) {
      j = next_bead(j);
      beads++;
    }
    cout << "tp2\n";
    j = prev_bead(i);
    while (intlace[j] == 0) {
      j = prev_bead(j);
      beads++;
    }
    cout << "tp3\n";
    bwcolor = intlace[j];
    j = prev_bead(j);
    while (((bwcolor*intlace[j]) > 0) or (intlace[j] == 0)) {
      j = prev_bead(j);
      beads++;
    }
    cout << "tp4\n";
    if (beads > maxbeads) maxbeads = beads;
    cout << "i=: " << i  << "\tcounts: " << beads << "\tmax: " << maxbeads << endl;
  }

  cout << "largest number of beads count: " << maxbeads << endl;
  
}


int next_bead(int idx) {
  return ((idx+1)%29);
}

int prev_bead(int idx) {
  return ((idx+29-1)%29);
}
