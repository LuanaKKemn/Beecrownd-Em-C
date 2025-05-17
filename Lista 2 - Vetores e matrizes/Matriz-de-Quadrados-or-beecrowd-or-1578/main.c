#include <stdio.h>

int main() {
  int n;
  int matrizes;
  int i, j;
  int m;
  int hashtagnum = 4;

  scanf("%d", &n);

  for (int matrizes = 0; matrizes < n; i++){
    scanf("%d", &m); // tamnho da matriz
    int matriz[m][m];

    for (i=0; i<m; i++){
      for (j=0; j<m; j++){
        scanf("%d ", &matriz[i][j]);
      }
    }
  }

  for (i=1; i <= n; i ++){
    printf("Quadrado da matriz #%d:", hashtagnum);
    hashtagnum++;
  }
  


  
  return 0;
}