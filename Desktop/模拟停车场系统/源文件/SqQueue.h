#define m 4
#include "Data.h"
typedef Data ElemType;
typedef struct Queue{
	ElemType elem[m];
	int front;
	int rear;
}enter,departrue;
//队列类型_入站队列，出站队列
void InitQueue(Queue &Q){
	Q.front=0;
	Q.rear=0;
}
//初始化队列 
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
//进入队列
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
//出队列，并赋值给e 
bool quEmpty(Queue &Q){
	if((Q.rear+1)%m!=Q.front){
		return true;
	}
	else{
		return false;
	}
}
//判断队列是否为有空位 
bool quEmpty0(Queue &Q){
	if(Q.front==Q.rear){
		return true;
	}
	else{
		return false;
	}
}
//判断队列是否为空 
void DisplayQueue_en(Queue Q){
	if(quEmpty0(Q)){
		printf("\n※当前等候入场通道无车辆。\n");
	}
	else{
		printf("\n※-------------------当前等候入站的车辆信息：\n");
		printf("车牌号码\n");
		printf("--------\n");
		for(int i=(Q.front+1)%m;i!=(Q.rear+1)%m;i=(i+1)%m){
			printf(" %d",Q.elem[i].number);
			printf("\n");
		}
	}
}
//输出入站等候队列 
void DisplayQueue_de(Queue Q){
	if(quEmpty0(Q)){
		printf("\n※当前等候出站通道无车辆。\n");
	}
	else{
		printf("\n※--------------------当前等候出站的车辆信息：\n");
		printf("停车位置         车牌号码          到达时间\n");
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
				printf("0%d：",Q.elem[i].arrive_hour);
			}
			else{
				printf("%d：",Q.elem[i].arrive_hour);
			}
			if(Q.elem[i].arrive_minute<=9){
				printf("0%d |\n",Q.elem[i].arrive_minute);
			}
			else{
				printf("%d |\n",Q.elem[i].arrive_minute);
			}
		}
		printf("※------------------------------------------\n");
	}
}
//输出出站等候队列 
