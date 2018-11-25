#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

int com; // 컴퓨터 숫자값 
int input; // 사용가 넣는 숫자값 
int count=5; //기회 

void checkUpdown(void) { // 컴퓨터랑 사용자의 숫자 비교 함수 

    if(input>com) {      // 사용자숫자가 컴퓨터숫자보다 클때 
        printf("Down !\n");
        printf("기회는 %d 남았습니다.\n\n",count);
        count--;

    } else if(input<com) {  // 사용자숫자가 컴퓨터숫자보다 작을때 
        printf("Up !\n");
        printf("기회는 %d 남았습니다.\n\n",count);
        count--;
    }
}

int main(void){

    srand(time(NULL));
    com = (rand()%11); //랜덤으로 컴퓨터숫자 변수 선언 (0~10) 
    
    int round[3] = {1,2,3}; //라운드 
    int round_num=0; //라운드진행 값 
	
    printf("============Up & Down Game============\n\n");
    printf("---- 게임 룰 ----\n\n");
    printf("3라운드까지 맞추셔야 끝납니다.\n");
    printf("기회는 총6번있습니다.\n그안에 맞추셔야 다음라운드로 넘어가고 못맞추시면 다시 처음부터 해야합니다.\n\n-----------------\n\n");
	printf("== %d 라운드 ==\n",*(round+round_num));
	
    while(1) {
		
        printf("숫자를 입력하세요[0~10]: ");
        scanf("%d", &input);
        checkUpdown();
        if(input == com){ // 사용자숫자가 컴퓨터숫자랑 같을때 
            printf("정답입니다!!!\n");
            round_num++; // 다음라운드 
            if(round_num==3){  //3라운드까지 성공하면 끝  
            	printf("\n\n★☆★수고하셨습니다.★☆★\n\n"); 
            	break; 
			}
			printf("%d 라운드로 넘어갑니다.\n\n",*(round+round_num));
			printf("== %d 라운드 ==\n\n",*(round+round_num));
			count=5; //기회값 다시 초기화 
			srand(time(NULL)); // 중복되지 않게 랜덤값 다시 생성 
    		com = (rand()%11); 
        }
        else if(count==-1){ //기회를 다썼을때 
        	printf("\n★☆★처음부터 다시합니다.★☆★\n\n");
        	round_num=0; //다시 1라운드 
        	count=5; //기회값 다시 초기화 
        	printf("== %d라운드 ==\n",*(round+round_num));
        	srand(time(NULL)); // 중복되지 않게 랜덤값 다시 생성 
    		com = (rand()%11);
        }
        
    	}
	
    system("pause");
    return 0; 
}
