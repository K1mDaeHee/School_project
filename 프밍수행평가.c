#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

int com; // ��ǻ�� ���ڰ� 
int input; // ��밡 �ִ� ���ڰ� 
int count=5; //��ȸ 

void checkUpdown(void) { // ��ǻ�Ͷ� ������� ���� �� �Լ� 

    if(input>com) {      // ����ڼ��ڰ� ��ǻ�ͼ��ں��� Ŭ�� 
        printf("Down !\n");
        printf("��ȸ�� %d ���ҽ��ϴ�.\n\n",count);
        count--;

    } else if(input<com) {  // ����ڼ��ڰ� ��ǻ�ͼ��ں��� ������ 
        printf("Up !\n");
        printf("��ȸ�� %d ���ҽ��ϴ�.\n\n",count);
        count--;
    }
}

int main(void){

    srand(time(NULL));
    com = (rand()%11); //�������� ��ǻ�ͼ��� ���� ���� (0~10) 
    
    int round[3] = {1,2,3}; //���� 
    int round_num=0; //�������� �� 
	
    printf("============Up & Down Game============\n\n");
    printf("---- ���� �� ----\n\n");
    printf("3������� ���߼ž� �����ϴ�.\n");
    printf("��ȸ�� ��6���ֽ��ϴ�.\n�׾ȿ� ���߼ž� ��������� �Ѿ�� �����߽ø� �ٽ� ó������ �ؾ��մϴ�.\n\n-----------------\n\n");
	printf("== %d ���� ==\n",*(round+round_num));
	
    while(1) {
		
        printf("���ڸ� �Է��ϼ���[0~10]: ");
        scanf("%d", &input);
        checkUpdown();
        if(input == com){ // ����ڼ��ڰ� ��ǻ�ͼ��ڶ� ������ 
            printf("�����Դϴ�!!!\n");
            round_num++; // �������� 
            if(round_num==3){  //3������� �����ϸ� ��  
            	printf("\n\n�ڡ١ڼ����ϼ̽��ϴ�.�ڡ١�\n\n"); 
            	break; 
			}
			printf("%d ����� �Ѿ�ϴ�.\n\n",*(round+round_num));
			printf("== %d ���� ==\n\n",*(round+round_num));
			count=5; //��ȸ�� �ٽ� �ʱ�ȭ 
			srand(time(NULL)); // �ߺ����� �ʰ� ������ �ٽ� ���� 
    		com = (rand()%11); 
        }
        else if(count==-1){ //��ȸ�� �ٽ����� 
        	printf("\n�ڡ١�ó������ �ٽ��մϴ�.�ڡ١�\n\n");
        	round_num=0; //�ٽ� 1���� 
        	count=5; //��ȸ�� �ٽ� �ʱ�ȭ 
        	printf("== %d���� ==\n",*(round+round_num));
        	srand(time(NULL)); // �ߺ����� �ʰ� ������ �ٽ� ���� 
    		com = (rand()%11);
        }
        
    	}
	
    system("pause");
    return 0; 
}
