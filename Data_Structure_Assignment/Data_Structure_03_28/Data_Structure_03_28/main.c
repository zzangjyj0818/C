#include <stdio.h>
#define MAX_TERMS 100

// 0이 아닌 원소값의 정보
typedef struct element{
    int row;
    int col;
    int value;
} element;

// 희소행렬의 정보
typedef struct SparseMatrix {
    element data[MAX_TERMS]; //항의 개수
    int rows; // 행의 개수
    int cols; // 열의 개수
    int terms; // 항의 개수

} SparseMatrix;


int a[8][10] = { { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
                 { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                 { 0, 0, 0, 0, 0, 0, 0,-3, 0, 0 },
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                 { 0,-1, 0, 0, 0, 0, 0, 0, 0, 0 },
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
                };

 

int b[8][10] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                 { 0, 0, 0,-1, 0, 0, 0, 0, 0, 0 },
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                 { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                 { 0, 0, 0, 0, 0, 0, 2, 0, 0, 0 }
               };

 

int c[8][10] = { { 0, 0, 0, 0,-2, 0, 0, 0, 0, 0 },
                 { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                 { 0, 0, 0, 0,-2, 0, 0, 0, 0, 0 },
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                 { 0, 0, 0, 0, 0, 0, 4, 0, 0, 0 }
               };

SparseMatrix A,B,C, result, transpose;

/* Print SparseMatrix */
void print_SparseMatrix(SparseMatrix p){
    printf("=============================\n");
    for(int i = 0; i<p.terms; i++){
        printf("row : %d | col : %d | value : %d \n", p.data[i].row, p.data[i].col, p.data[i].value);
    }
    printf("\nrows : %d | cols : %d | terms : %d\n", p.rows, p.cols, p.terms);
    printf("=============================\n");
}

/* Array to SparseMatrix */

void arr_to_SparseMatrix(SparseMatrix *tmp, int arr[8][10]){
    
    //배열의 정보를 구조체에 저장함
    tmp->terms = 0;
    
    // 8 by 10 Matrix
    tmp->rows = 8;
    tmp->cols = 10;
    
    for(int i = 0; i<8; i++){
        for(int j = 0; j<10; j++){
            if(arr[i][j] != 0){
                tmp->data[tmp->terms].row = i;
                tmp->data[tmp->terms].col = j;
                tmp->data[tmp->terms].value = arr[i][j];
                tmp->terms++;
            }
        }
    }
    print_SparseMatrix(*tmp);
    
}

/* SparseMatrix Add Fuction */
SparseMatrix add(SparseMatrix *x, SparseMatrix *y, SparseMatrix *result){
    int cnt_x = 0, cnt_y = 0, cnt_z = 0;
    
    //결과값을 담을 구조체에 행과 열의 정보를 넣어줌
    result->rows = x->rows;
    result->cols = x->cols;
    
    
    result->terms = 0;
    
    while(cnt_x < x->terms && cnt_y < y->terms){
        //해당 원소의 위치
        int first_x = x->data[cnt_x].row*(x->cols) + x->data[cnt_x].col;
        int first_y = y->data[cnt_y].row*(y->cols) + y->data[cnt_y].col;
        
        //x의 원소가 y의 원소보다 빠르다면
        if(first_x < first_y){
            result->data[cnt_z++] = x->data[cnt_x++];
        }
        else if(first_x == first_y){
            if(x->data[cnt_x].value + y->data[cnt_y].value != 0){
                result->data[cnt_z].row = x->data[cnt_x].row;
                result->data[cnt_z].col = x->data[cnt_x].col;
                result->data[cnt_z++].value = x->data[cnt_x++].value + y->data[cnt_y++].value;
            }
            else{
                cnt_x++;
                cnt_y++;
            }
        }
        else{
            result->data[cnt_z++] = y->data[cnt_y++];
        }
    }
    
    
    for(;cnt_x<x->terms;)
        result->data[cnt_z++] = x->data[cnt_x++];
    for(;cnt_y < y->terms;)
        result->data[cnt_z++] = y->data[cnt_y++];
    
    result->terms = cnt_z;
    
    return *result;
}

/* SparseMatrix to array */
void SparseMatrix_to_arr(SparseMatrix *p){
    int index = 0;
    
    printf("\n===========================================\n\n");
    for(int i = 0; i<p->rows; i++){
        for(int j = 0; j<p->cols; j++){
            // Matrix(i,j)에 값이 들어있다면, 그 값을 출력
            // 값이 없다면 그냥 0 출력
            if((p->data[index].row == i) && (p->data[index].col == j))
                printf("%d\t", p->data[index++].value);
            else
                printf("0\t");
        }
        printf("\n");
    }
    printf("\n===========================================\n\n");
}

/* 전치행렬 */
SparseMatrix Transpose(SparseMatrix *A, SparseMatrix *transpose){
    
    //열과 행을 서로 바꾸어 넣어줌
    transpose->rows = A->cols;
    transpose->cols = A->rows;
    transpose->terms = A->terms;
    
    //열의 개수를 셀 배열
    int count[transpose->cols];
    
    //데이터의 순서를 넣어줄 배열
    int starting_pos[transpose->cols];
    
    
    //열의 개수를 셀 배열을 0으로 초기화
    for(int i = 0; i<transpose->cols; i++)
        count[i] = 0;
    
    // Col Count
    for(int i = 0; i<transpose->terms; i++)
        count[A->data[i].col]++;
    
    printf("<Col Count>\n");
    for(int i = 0; i< transpose->cols; i++)
        printf("%5d", count[i]);
    printf("\n");
    
    starting_pos[0] = 0;
    for(int i = 1; i < transpose->cols; i++)
        starting_pos[i] = starting_pos[i-1] + count[i-1];

    printf("<Starting_Pos>\n");
    for(int i = 0; i< transpose->cols; i++)
        printf("%5d", starting_pos[i]);
    printf("\n");
    
    for(int i = 0; i<transpose->terms; i++){
        int index = starting_pos[A->data[i].col]++;
        transpose->data[index].row = A->data[i].col;
        transpose->data[index].col = A->data[i].row;
        transpose->data[index].value = A->data[i].value;
    }
    
    
    return *transpose;
}


/* Print Menu */

void print_menu(){
    int menu;
    while(1){
        printf("메뉴 입력 (1-5) : ");
        scanf("%d", &menu);
        
        switch(menu){
        case 1:
            arr_to_SparseMatrix(&A, a);
            arr_to_SparseMatrix(&B, b);
            arr_to_SparseMatrix(&C, c);
            break;
        case 2:
            printf("<A+B> \n");
            add(&A,&B, &result);
            SparseMatrix_to_arr(&result);
                
            printf("<A+C> \n");
            add(&A,&C, &result);
            SparseMatrix_to_arr(&result);
            
            printf("<B+C> \n");
            add(&B,&C, &result);
            SparseMatrix_to_arr(&result);
            break;
        case 3:
            printf("<A> \n");
            SparseMatrix_to_arr(&A);
                
            printf("<B> \n");
            SparseMatrix_to_arr(&B);
            
            printf("<C> \n");
            SparseMatrix_to_arr(&C);
            break;
        case 4:
                Transpose(&A, &transpose);
                print_SparseMatrix(transpose);
                SparseMatrix_to_arr(&transpose);
            break;
        case 5:
            printf("프로그램을 종료합니다.\n");
            return;
            break;
        default:
            printf("다시 입력하세요.\n");
            break;
        }
    }
}

int main(){
    print_menu();
    return 0;
}
