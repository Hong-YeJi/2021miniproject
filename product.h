// product.h

typedef struct {
  char product_name[80]; // 제품명
  double weight; // 중량
  int price; // 판매가격
  int star; // 별점 1~5까지의 숫자
  int star_num; // 별점 개수
} Product;

int selectMenu(); // (제품 조회, 제품 추가, 제품 수정, 제품 삭제, 파일 저장, 제품 검색, 종료) 메뉴 선택하는 함수
int createProduct(Product *p); // 제품을 추가하는 함수 (C)
int readProduct(Product p); // 하나의 제품 출력 함수 (R)
int updateProduct(Product *p); // 제품을 수정하는 함수 (U)
int deleteProduct(Product *p); // 제품을 삭제하는 함수 (D)
void listProduct(Product *p[], int count); // 전체 등록된 제품 리스트 출력 - 반환형 수정
void saveData(Product *p[], int count); // 파일 저장하는 함수
int loadData(Product *p[]); // 파일에서 데이터 불러오는 함수
int selectDataNo(Product *p[], int count); // 선택한 데이터 번호를 저장하는 함수
void searchProduct(Product *p[], int count); // 제품 이름 검색 (검색기능 1)
void searchProductWeight(Product *p[], int count); // 제품 중량 검색 (검색기능 2)
void searchProductPrice(Product *p[], int count); // 제품 판매 가격 검색 (검색기능 3)

