// product.c
#include <stdio.h>
#include <stdlib.h>
#include "product.h"

int selectMenu(){
	int menu;
	printf("\n*** 쇼핑물 프로그램 ***\n");
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 파일저장\n");
	printf("6. 제품이름검색\n");
	printf("7. 제품중량검색\n");
	printf("8. 제품가격검색\n");
	printf("0. 종료\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d", &menu);

	return menu;
}

int createProduct(Product *p){
	getchar();
	printf("\n제품 이름은? ");
	scanf("%[^\n]s", p->product_name);
	printf("제품 중량은? ");
	scanf("%lf", &p->weight);
	printf("제품 가격은? ");
	scanf("%d", &p->price);
	while(1){
		printf("제품 별점은? ");
		scanf("%d", &p->star);
		if(0 < p->star && p->star < 6) break;
		else printf("1~5까지의 숫자를 입력해주세요!\n");
	}	
	printf("제품 별점 개수는? ");
	scanf("%d", &p->star_num);
	printf("=> 추가됨!\n");

	return 1;
}

int readProduct(Product p){
	int price_100g = 0;
	if(p.price == -1) return 0;

	// printf("\n----------제품 정보----------\n"); - 수정(주석처리)
	if((p.weight - (int)p.weight) != 0){
		price_100g = (int)(p.price/((p.weight*1000)/100)+0.9); // 올림으로 계산
		printf("%s\n", p.product_name); 
		printf("%d원\n", p.price);
		printf("(100g당:%d원)\n", price_100g);
	}
	else{
		price_100g = (int)(p.price/(p.weight/100)+0.9); // 올림으로 계산
		printf("%s\n", p.product_name); 
		printf("%d원\n", p.price);
		printf("(100g당:%d원)\n", price_100g);
	}
	if(p.star == 1) printf("* ");
	else if(p.star == 2) printf("** ");
	else if(p.star == 3) printf("*** ");
	else if(p.star == 4) printf("**** ");
	else printf("***** ");

	printf("(%d개)\n", p.star_num);
	
	return 1;
}

int updateProduct(Product *p){
	getchar();
	printf("\n새 제품 이름은? ");
	scanf("%[^\n]s", p->product_name);
	getchar();
	printf("새 제품 중량은? ");
	scanf("%lf", &p->weight);
	printf("새 제품 가격은? ");
	scanf("%d", &p->price);
	while(1){
		printf("새 제품 별점은? ");
		scanf("%d", &p->star);
		if(0 < p->star && p->star < 6) break;
		else printf("1~5까지의 숫자를 입력해주세요!\n");
	}	
	printf("새 제품 별점 개수는? ");
	scanf("%d", &p->star_num);
	printf("=> 수정됨!\n");

	return 1;
}

int deleteProduct(Product *p){
	p->price = -1;

	return 1;
}
	
