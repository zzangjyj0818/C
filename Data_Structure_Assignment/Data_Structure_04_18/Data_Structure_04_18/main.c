#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_SIZE 100
#define MAZE_SIZE 10

/* Num 1 */
//Use Stack -> Print the Escaping Route about maze
//Maze init
int maze[MAZE_SIZE][MAZE_SIZE] = {
  // start coodinate (1,0) / finish coordinate (6,9)
  // 0  1  2  3  4  5  6  7  8  9
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 0
    {0, 0, 1, 0, 0, 0, 1, 1, 1, 1}, // 1
    {1, 0 ,0 ,0, 1, 1, 1, 1, 1, 1}, // 2
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1}, // 3
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 1}, // 4
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1}, // 5
    {1, 1, 1, 0, 0, 0, 1, 0, 0, 0}, // 6
    {1, 1, 1, 1, 1, 0, 1, 0, 1, 1}, // 7
    {1, 1, 1, 1, 1, 0, 0, 0, 1, 1}, // 8
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}  // 9
};

// (x, y) & direction
typedef struct coordinate{
    int r;
    int c;
    int dir; // 0 E, 1 S, 2 W, 3 N
}coordinate;


//Declare the Stack Struct
typedef struct StackType{
    coordinate data[MAX_SIZE];
    int top;
} StackType;

// Init the Stack
void init_stack(StackType *s){
    s->top = -1;
}

// Check the Stack (Empty)
int stack_empty(StackType *s){
    return (s->top == -1);
}

// Check the Stack (Full)
int stack_full(StackType *s){
    return (s->top == (MAX_SIZE-1));
}

// Insert the item in the Stack
void push(StackType *s, coordinate item){
    if(stack_full(s)){
        fprintf(stderr, "Stack is Full!\n");
        return;
    }else{
        s->data[++(s->top)] = item;
    }
}

// Delete the top of Stack
coordinate pop(StackType *s){
    if(stack_empty(s)){
        fprintf(stderr, "Stack is Empty!\n");
        exit(1);
    }else{
        return s->data[(s->top)--];
    }
}

// Print the route about Escaping Maze
void printRoute(StackType *s){
    if(!stack_empty(s)){
        for(int i = 0; i < s->top; i++)
            printf("Route[%d] : %d %d %d[dir]\n", i+1, s->data[i].r, s->data[i].c, s->data[i].dir);
    }
}

// init route
void initRoute(coordinate *route){
    route->r = 1;
    route->c = 1;
    route->dir = 0;
}

void moveCoordinate(coordinate *route){
    switch(route->dir){
        case 0: route->c++; break; // East
        case 1: route->r++; break; // South
        case 2: route->c--; break; // West
        case 3: route->r--; break; // North
    }
    route->dir = 0; // Init the direction
    maze[route->r][route->c] = 1; // 현재 이동한 지점 1로 표시
}

int possible(int r, int c, int dir){
    switch(dir){
    case 0: c++; break;
    case 1: r++; break;
    case 2: c--; break;
    case 3: r--; break;
    }
    if(maze[r][c] == 1)
        return 0;
    else
        return 1;
}

void escape_maze(){
    StackType s;
    coordinate route;
    
    init_stack(&s);
    initRoute(&route);

    push(&s, route);
    
    while(!stack_empty(&s)){
        route = pop(&s);
        //시도 할 방향이 있으면 계속 시도함
        while(route.dir <= 3){
            //탈출구에 도착하면 메뉴로 return
            if(route.r == 6 && route.c == 9){
                push(&s, route);
                printRoute(&s);
                return;
            }else{
                // 이동가능한 방향이 있다면
                if(possible(route.r, route.c, route.dir) == 1){
                    push(&s, route);
                    moveCoordinate(&route);
                }else{
                    route.dir += 1;
                }
            }
        }
    }
}
/* ===================================================================== */
/* Num2 */
typedef struct inf{
    int id;
    int arrival_time;
    int service_time;
} inf;

/* Num3 */
typedef struct element{
    int count;
    char name[100];
} element;

// Declare the Queue Struct
typedef struct QueueType{
    inf data[MAX_SIZE];
    element student[MAX_SIZE];
    int front, rear;
} QueueType;

//Print Error
void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void queue_init(QueueType *q){
    q->front = q->rear = 0;
}

int queue_empty(QueueType *q){
    return (q->front == q->rear);
}

int queue_full(QueueType *q){
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

/* ========================================= */
void enqueue_num2(QueueType *q, inf item){
    if (queue_full(q)){
        error("포화상태입니다.\n");
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = item;
}

inf dequeue_num2(QueueType *q){
    if (queue_empty(q)){
        error("공백상태입니다.\n");
    }
    q->front = (q->front + 1) % MAX_SIZE;
    return q->data[q->front];
}
/* ========================================= */
void enqueue_num3(QueueType *q, element item){
    if (queue_full(q)){
        error("포화상태입니다.\n");
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->student[q->rear] = item;
}
element dequeue_num3(QueueType *q){
    if (queue_empty(q)){
        error("공백상태입니다.\n");
    }
    q->front = (q->front + 1) % MAX_SIZE;
    return q->student[q->front];
}
/* ========================================= */
/* Num2 */
void bank(){
    int min = 60;
    int total_wait = 0, total_customers = 0;
    int a_time = 0, b_time = 0;
    int a_customer, b_customer;
    int a_service = 1, b_service = 1;
    
    QueueType q;
    queue_init(&q);
    
    srand(time(NULL));
    for(int clock = 0; clock < min; clock++){
        printf("Current Time : %d\n", clock);
        printf("A 창구 : %d | B 창구 : %d (0. 업무 중 | 1. 업무 x )\n\n", a_service, b_service);
        if((rand() % 10 < 3)){
            inf customer;
            customer.id = total_customers++;
            customer.arrival_time = clock;
            customer.service_time = rand() % 3 + 1;
            enqueue_num2(&q, customer);
            printf("고객 %d이 %d분에 들어옵니다. 고객 업무처리시간 = %d\n\n",customer.id,customer.arrival_time,customer.service_time);
        }
        if(a_time > 0){
            printf("고객 %d가 A창구에서 업무처리 중입니다.\n", a_customer);
            a_time--;
            if(a_time == 0){
                printf("A창구가 %d분에 열립니다.\n\n", clock+1);
                a_service = 1;
            }
        }else if(a_service){
            if(!queue_empty(&q)){
                inf customer = dequeue_num2(&q);
                a_customer = customer.id;
                a_time = customer.service_time;
                printf("고객 %d이 %d분에 업무를 시작합니다.(A창구) 대기시간은 %d분이었습니다.\n\n",customer.id, clock, clock - customer.arrival_time);
                a_service = 0;
                total_wait += clock - customer.arrival_time;
            }
        }
        
        if(b_time > 0){
            printf("고객 %d가 B창구에서 업무처리 중입니다.\n", b_customer);
            b_time--;
            if(b_time == 0){
                printf("B창구가 %d분에 열립니다.\n\n", clock+1);
                b_service = 1;
            }
        }
        else if(b_service){
            if(!queue_empty(&q)){
                inf customer = dequeue_num2(&q);
                b_customer = customer.id;
                b_time = customer.service_time;
                printf("고객 %d이 %d분에 업무를 시작합니다.(B창구) 대기시간은 %d분이었습니다.\n\n",customer.id, clock, clock - customer.arrival_time);
                b_service = 0;
                total_wait += clock - customer.arrival_time;
            }
        }
    }
    
}

/* Num3 */
void matching(){
    QueueType man, woman;
    
    queue_init(&man);
    queue_init(&woman);
    
    srand(time(NULL));
    
    int count = 100;
    int man_i = 0, woman_i = 0;
    element tmp;
    
    while(count--){
        int num = rand() % 2 + 1;
        char str[100];
        
        if(num % 2 == 0){
            printf("남자 %d의 이름 입력 : ", man_i+1);
            scanf("%s", str);
            
            tmp.count = man_i+1;
            strcpy(tmp.name, str);
            
            enqueue_num3(&man, tmp);
            printf("남자%d(%s) 입장", man_i+1, str);
            man_i++;
        }else{
            printf("여자 %d의 이름 입력 : ", woman_i+1);
            scanf("%s", str);
            
            tmp.count = woman_i+1;
            strcpy(tmp.name, str);
            
            enqueue_num3(&woman, tmp);
            printf("여자%d(%s) 입장", woman_i+1, str);
            woman_i++;
        }
        
        if(!queue_empty(&man) && !queue_empty(&woman)){
            element tmp1 = dequeue_num3(&man);
            element tmp2 = dequeue_num3(&woman);
            printf("- 여자%d(%s) / 남자%d(%s) 매칭\n", tmp2.count, tmp2.name, tmp1.count, tmp1.name);
            
        }else{
            printf(" - 대기\n");
        }
    }
}
void print_menu(){
    int menu;
    
    while(1){
        printf("\nSelect the menu (1-4) : ");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                escape_maze();
                break;
            case 2:
                bank();
                break;
            case 3:
                matching();
                break;
            case 4:
                printf("Exit the Program\n");
                return;
                break;
            default:
                printf("Wrong Menu\n");
                break;
        }
    }
}
int main(void){
    print_menu();
}
