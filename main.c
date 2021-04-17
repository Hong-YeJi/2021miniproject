// main.c
#include <stdio.h>
#include <stdlib.h>
#include "manager.h"

int main(){
	Product *p[100];
	int index = 0;
	int count = 0;
	int menu;

	count = loadData(p);
	index = count;
	
	while(1){
		menu = selectMenu();
		if(menu == 0) break;
		if(menu == 1 || menu == 3 || menu == 4){
			if(count == 0){
				printf("데이터가 없습니다.\n");
				continue;
			}
		}
		if(menu == 1){
			#ifdef DEBUG
				printf("=>Debug: count =  %d\n", count);
			#endif	
			listProduct(p, index);
		}
		else if(menu == 2){
			#ifdef DEBUG
                                printf("=>Debug: 제품추가 전, count =  %d\n", count);
                        #endif
			p[index] = (Product *)malloc(sizeof(Product));
		       	count += createProduct(p[index++]);
			#ifdef DEBUG
                                printf("=>Debug: 제품추가 후, count =  %d\n", count);
                        #endif
		}
		else if(menu == 3){
			int no = selectDataNo(p, index);
			if(no == 0){
				printf("=> 취소됨!\n");
				continue;
			}
			updateProduct(p[no-1]);
		}
		else if(menu == 4){
			int no = selectDataNo(p, index);
			if(no == 0){
				printf("=> 취소됨!\n");
				continue;
			}
			int delok;
			printf("정말로 삭제하시겠습니까?(삭제:1)");
			scanf("%d", &delok);
			
			if(delok == 1){
				#ifdef DEBUG
                                	printf("=>Debug: 삭제 전, count =  %d\n", count);
                       		#endif
				int isdel = deleteProduct(p[no-1]);
	                	if(isdel == 1){
					free(p[no-1]);
        	                        printf("=> 삭제됨!\n");
                                	count--;
					#ifdef DEBUG
                                        	printf("=>Debug: 삭제 후, count =  %d\n", count);
                               		#endif
                       		}
			}
		}
		else if(menu == 5){
			saveData(p, index);
		}
		else if(menu == 6){
			searchProduct(p, index);
		}
		else if(menu == 7){
			searchProductWeight(p, index);
		}
		else if(menu == 8){
			searchProductPrice(p, index);
		}	
	}
	printf("종료됨!\n");
	return 0;
}

