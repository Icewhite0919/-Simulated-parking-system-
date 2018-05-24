#define m 4
#include "Data.h"
typedef Data ElemType;
typedef struct Queue{
	ElemType elem[m];
	int front;
	int rear;
}enter,departrue;
//��������_��վ���У���վ����
void InitQueue(Queue &Q){
	Q.front=0;
	Q.rear=0;
}
//��ʼ������ 
bool enQueue(Queue &Q,ElemType e){
	if((Q.rear+1)%m==Q.front){
		return false;
	}
	else{
		Q.rear=(Q.rear+1)%m;
		Q.elem[Q.rear]=e;
		return true;
	}
}
//�������
bool deQueue(Queue &Q,ElemType &e){
	if(Q.front==Q.rear){
		return false;
	}
	else{
		Q.front=(Q.front+1)%m;
		e=Q.elem[Q.front];
		return true;
	}
}
//�����У�����ֵ��e 
bool quEmpty(Queue &Q){
	if((Q.rear+1)%m!=Q.front){
		return true;
	}
	else{
		return false;
	}
}
//�ж϶����Ƿ�Ϊ�п�λ 
bool quEmpty0(Queue &Q){
	if(Q.front==Q.rear){
		return true;
	}
	else{
		return false;
	}
}
//�ж϶����Ƿ�Ϊ�� 
void DisplayQueue_en(Queue Q){
	if(quEmpty0(Q)){
		printf("\n����ǰ�Ⱥ��볡ͨ���޳�����\n");
	}
	else{
		printf("\n��-------------------��ǰ�Ⱥ���վ�ĳ�����Ϣ��\n");
		printf("���ƺ���\n");
		printf("--------\n");
		for(int i=(Q.front+1)%m;i!=(Q.rear+1)%m;i=(i+1)%m){
			printf(" %d",Q.elem[i].number);
			printf("\n");
		}
	}
}
//�����վ�Ⱥ���� 
void DisplayQueue_de(Queue Q){
	if(quEmpty0(Q)){
		printf("\n����ǰ�Ⱥ��վͨ���޳�����\n");
	}
	else{
		printf("\n��--------------------��ǰ�Ⱥ��վ�ĳ�����Ϣ��\n");
		printf("ͣ��λ��         ���ƺ���          ����ʱ��\n");
		for(int i=(Q.front+1)%m;i!=(Q.rear+1)%m;i=(i+1)%m){
			printf("  %d              ",Q.elem[i].position);
			printf("%d",Q.elem[i].number);
			int q,k=1;
			for(q=1;q<=16;q++){
				k=k*10;
				if(Q.elem[i].number/k==0){
					break;
				}
			}
			for(int l=0;l<=16-q;l++){
				printf(" ");
			}
			if(Q.elem[i].arrive_hour<=9){
				printf("0%d��",Q.elem[i].arrive_hour);
			}
			else{
				printf("%d��",Q.elem[i].arrive_hour);
			}
			if(Q.elem[i].arrive_minute<=9){
				printf("0%d |\n",Q.elem[i].arrive_minute);
			}
			else{
				printf("%d |\n",Q.elem[i].arrive_minute);
			}
		}
		printf("��------------------------------------------\n");
	}
}
//�����վ�Ⱥ���� 
