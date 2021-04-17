// manager.c
#include "manager.h"
#include <stdlib.h>
#include <string.h>

void listProduct(Product *p[], int count){
	printf("\n##############제품 리스트##############\n");
	for(int i = 0 ; i < count ; i++){
		if(p[i]->price == -1) continue;
		printf("[------------%d번제품 정보------------]\n", i+1);
		readProduct(*p[i]);
	}
}

int selectDataNo(Product *p[], int count){
	int no;
	listProduct(p, count);
	printf("\n번호는 (취소:0)? ");
	scanf("%d", &no);

	return no;
}

void saveData(Product *p[], int count){
	FILE *fp;
	fp = fopen("product.txt", "wt");

	for(int i = 0 ; i < count ; i++){
		if(p[i]->price == -1) continue;
		fprintf(fp, "%s %.1f %d %d %d\n", p[i]->product_name, p[i]->weight,
				p[i]->price, p[i]->star, p[i]->star_num);
	}

	fclose(fp);
	printf("저장 성공!\n");
}

int loadData(Product *p[]){
	int i = 0;
	FILE *fp;
	fp = fopen("product.txt", "rt");

	if(fp == NULL){
		printf("=> 파일 없음!\n");
		return 0;
	}
	
	for(; i < 100 ; i++){
		p[i] = (Product *)malloc(sizeof(Product));	
		fscanf(fp, "%s", p[i]->product_name);
		if(feof(fp)) break;
		fscanf(fp, "%lf", &p[i]->weight);
		fscanf(fp, "%d", &p[i]->price);
		fscanf(fp, "%d", &p[i]->star);
		fscanf(fp, "%d", &p[i]->star_num);
	}

	fclose(fp);
	printf("=> 로딩 성공!\n");
	return i;
}

void searchProduct(Product *p[], int count){
	int scnt = 0;
	char search_name[80];

	printf("검색할 제품? ");
	scanf("%s", search_name);

	printf("\n##############제품 리스트##############\n");
        for(int i = 0 ; i < count ; i++){
                if(p[i]->price == -1) continue;
		if(strstr(p[i]->product_name, search_name)){
                	printf("[------------%d번제품 정보------------]\n", i+1);
                	readProduct(*p[i]);
			scnt++;
		}
        }
	if(scnt == 0) printf("=> 검색된 제품명 없음!\n");

}

void searchProductWeight(Product *p[], int count){
	int scnt = 0;
        double search_weight;

        printf("검색할 제품 중량은? ");
        scanf("%ld", &search_weight);

        printf("\n##############제품 리스트##############\n");
        for(int i = 0 ; i < count ; i++){
                if(p[i]->price == -1) continue;
                if(p[i]->weight ==  search_weight){
                        printf("[------------%d번제품 정보------------]\n", i+1);
                        readProduct(*p[i]);
                        scnt++;
                }
        }
        if(scnt == 0) printf("=> 검색된 제품 중량 없음!\n");
}
