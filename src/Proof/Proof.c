#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Array.h"
#include "Proof.h"
  
  typedef struct point{
          int x;
          int y;
  }point;
  
void show(point * p){
	if(!p)
		return;
printf("\n Py = %d Px = %d", p->y, p->x);
}
  int main(){
  
          array * con = new(sizeof(point));
          if(!con)
                  return 1;
          point primer;
	primer.x = 23;
	primer.y = 52;
 	printf("\nson iguales %d\n", equal_o(&primer, &primer, sizeof(point))); 
          for(int i = 0; i<15; i++){
		primer.x = 3+i;
		primer.y = i*2;
		
                  add(con, &primer);
		show(get(con, i));
				}
 	printf("\nson iguales %d\n", equal_o(get(con,12),get(con,9), sizeof(point))); 
	printf("\n");
          destroy(con);

return 0;
}



