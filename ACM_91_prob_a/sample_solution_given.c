/*
   1991 ACM Finals, Problem A, Firetruck
   Ed Karrels, Feb. 1996
*/

#include <stdio.h>

int n_solns;

void Try(int ist[22][22], int pos, int fire, int mv[], int mv_no) {
   int i, j;

   if (pos == fire) {
      n_solns++;
      for (i=0; i<mv_no; i++) {
	 printf("%4d", mv[i]);
      } putchar('\n');
      return;
   }

   for (i=0; i<22; i++) {
      if (ist[pos][i]) {
	 for (j=0; j<mv_no; j++) {
	    if (mv[j] == i) break;
	 }
	 if (j == mv_no) {
	    mv[mv_no] = i;
	    Try(ist, i, fire, mv, mv_no+1);
	 }
      }
   }
}


int main(void) {
   int fire;
   int x, y;
   int ist[22][22];
   int mv[22], n_m;
   int cas = 1;

   while (1 == scanf("%d", &fire)) {

      for (x=0; x<22; x++)
	 for (y=0; y<22; y++)
	    ist[x][y] = 0;

      scanf("%d %d", &x, &y);
      while (x || y) {
	 ist[x][y] = 1; ist[y][x] = 1;
	 scanf("%d %d", &x, &y);
      }

      printf("CASE %d:\n", cas++);
      mv[0] = 1;
      n_solns = 0;
      Try(ist, 1, fire, mv, 1);
      printf("There are %d routes from the firestation to streetcorner %d.\n",
	     n_solns, fire);
   }

   return 0;
}

      
