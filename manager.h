// manager.h
#include <stdio.h>
#include "product.h"

void listProduct(Product *p[], int count); // 전체 등록된 제품 리스트 출력

int selectDataNo(Product *p[], int count); // 선택한 데이터 번호를 저장하는 함수

void saveData(Product *p[], int count); // 파일 저장하는 함수

int loadData(Product *p[]); // 파일에서 데이터 불러오는 함수

void searchProduct(Product *p[], int count); // 제품 이름 검색 (검색기능 1)

void searchProductWeight(Product *p[], int count); // 제품 중량 검색 (검색기능 2)

void searchProductPrice(Product *p[], int count); // 제품 판매 가격 검색 (검색기능 3)

