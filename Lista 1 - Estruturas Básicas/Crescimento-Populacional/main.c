#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++){
    int pa, pb, contador = 0;
    float ga, gb;
    scanf("%d %d %f %f", &pa, &pb, &ga, &gb);

    gb /= 100;
  
    
    while (pa <= pb){
      pa += (int)(pa * (ga / 100)); 
      pb += (int)(pb *gb); // graças ao universo
      contador += 1;
    
      if (contador > 100){
        printf("Mais de 1 seculo.\n");
        break;
      }
    }
    if (contador <= 100){
      printf("%d anos.\n", contador);
    }
  }
  return 0;
}