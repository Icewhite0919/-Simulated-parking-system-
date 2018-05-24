#include <stdio.h>
#include "SqQueue.h"
#define n 7
typedef Data ElemType;
typedef struct{
	ElemType elem[n];
}SqList;
//��λ��Ϣ
bool parkingspaceEmpty(ElemType e){
	if(e.number==-1&&e.arrive_hour==0&&e.arrive_minute==0){
		return true;
	}
	else{
		return false;
	}
}
//ĳ����λ�Ƿ�Ϊ��
bool allparkingspaceEmpty(SqList L){
	bool empty=false;
	for(int i=0;i<n;i++){
		if(parkingspaceEmpty(L.elem[i])){
			empty=true;
			break;
		}
	}
	return empty;
}
//�ж��Ƿ��пճ�λ 
bool setDefault(SqList &L,int position){
	if(position>=110&&position<=116){
		L.elem[position-110].position=position;
		L.elem[position-110].number=-1;
		L.elem[position-110].arrive_hour=0;
		L.elem[position-110].arrive_minute=0;
		return true;
	}
	else{
		return false;
	}
}
//��λ��ϢĬ������(�����뿪ʱ)
void setAllDefault(SqList &L){
	for(int i=110;i<117;i++){
		setDefault(L,i);
	}
	for(int i=1;i<7;i++){
		L.elem[i].number=i;
		L.elem[i].arrive_hour=12;
		L.elem[i].arrive_minute=20;
	}//�Զ������� 
}
//��ʼ������ 
bool parking(SqList &L,ElemType e,int position){
	if(position>=110&&position<=116&&parkingspaceEmpty(L.elem[position-110])){
		L.elem[position-110]=e;
		return true;
	}
	else{
		return false;
	}
}
//��վͣ��
bool departure(SqList &L,Queue &dep,int number){
	bool a=false;
	if(quEmpty(dep)){
		for(int i=0;i<n;i++){
			if(L.elem[i].number==number){
				a=enQueue(dep,L.elem[i]);
				if(a){
					setDefault(L,L.elem[i].position);
			}
				break;
			}
		}
		return a;
	}
	else{
		return false;
	}
}
//�뿪��λ����Ⱥ��վ���� 
void Display(SqList L){
	printf("\nͣ��λ��         ���ƺ���          ����ʱ��\n");
	printf("--------------------------------------------\n");
	for(int i=0;i<n;i++){
		printf("| %d              ",i+110);
		if(parkingspaceEmpty(L.elem[i])){
		printf("none              none  |\n");
		}
		else{
			printf("%d",L.elem[i].number);
			int q,k=1;
			for(q=1;q<=16;q++){
				k=k*10;
				if(L.elem[i].number/k==0){
					break;
				}
			}
			for(int l=0;l<=16-q;l++){
				printf(" ");
			}
			if(L.elem[i].arrive_hour<=9){
				printf("0%d��",L.elem[i].arrive_hour);
			}
			else{
				printf("%d��",L.elem[i].arrive_hour);
			}
			if(L.elem[i].arrive_minute<=9){
				printf("0%d |\n",L.elem[i].arrive_minute);
			}
			else{
				printf("%d |\n",L.elem[i].arrive_minute);
			}
		}
	}
	printf("--------------------------------------------\n");
}
//��ʾ��ǰ��λ��Ϣ 
