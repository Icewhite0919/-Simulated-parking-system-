#include <iostream>
#include <String.h>
#include "SqList.h"
#define B 3//ÿСʱ��Ԫ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	int choose;                      //������� 
	bool run=true;                   //��������״̬ 
	bool data_position=false;     	 //����λ�úϷ�״̬
	bool data_time=false;            //����ʱ��Ϸ�״̬ 
	Data car;                        //�� 
	int position;                    //ͣ��λ�� 
	int number;                      //���ƺ��� 
	int arrive_hour;                 //����ʱ��_Сʱ 
	int arrive_minute;               //����ʱ��_���� 
	int hour;                        //����ʱ��_Сʱ 
	int minute;                      //����ʱ��_���� 
	float sum;                       //�շ� 
	SqList parkingspace;             //��λ 
	enter waitingqueue_en;           //��վ�Ⱥ���� 
	departrue waitingqueue_de;       //��վ�Ⱥ���� 
	InitQueue(waitingqueue_en);
	InitQueue(waitingqueue_de);
	int q=17;
	int k=1;
	//������� 
	setAllDefault(parkingspace);
	while(run){
		printf("\n��ǰ��λ��Ϣ��\n");
		Display(parkingspace);
		DisplayQueue_en(waitingqueue_en);
		DisplayQueue_de(waitingqueue_de);
		printf("\nѡ���ܣ� 1����վ��\n           2����վ��\n           3�����������Ʒѣ�\n           4���˳�ϵͳ\n--------------------------------------------\n");
		scanf("%d",&choose);
		switch(choose){
			case 1:
				if(allparkingspaceEmpty(parkingspace)){
					while(!data_position||!data_time){
						defaultInit(car);
						printf("������������Ϣ��\n");	
						printf("�������볡ͣ����λ�ã�����Ϊ��ǰ�ճ�λ����");
						scanf("%d",&position);
						printf("�����복�ƺ��루�����֣���");
						scanf("%d",&number);
						while(q>11){
							for(q=1;q<=17;q++){
								k=k*10;
								if(number/k==0){
									break;
								}
							}
							if(q>11){
								printf("���������ֳ���11λ��\n");
								printf("�����복�ƺ��루�����֣���");
								scanf("%d",&number);
							}
						}
						q=17;
						k=1;
						setNumber(car,number);
						printf("����ʱ�䣨�밴��ʽ����������Ը���\n���������ʽ   Сʱ������    \nð��ӦΪ�������뷨�µ�ð�ţ���");
						scanf("%d��%d",&arrive_hour,&arrive_minute);
						data_position=setPosition(car,position);
						data_time=setArrivetime(car,arrive_hour,arrive_minute);
						if(!data_position||!data_time){
							printf("����������������ϸ��������ʽ��\n");
						}
					}
					data_position=false;
					data_time=false;
					parking(parkingspace,car,position);
				}
				else if(!allparkingspaceEmpty(parkingspace)&&quEmpty(waitingqueue_en)){
					defaultInit(car);
					printf("�����복�ƺ��루�����֣���");
					scanf("%d",&number);
					setNumber(car,number);
					enQueue(waitingqueue_en,car);
				}
				else{
					printf("��ͣ�������������ұ��ͣ����ͣ����");
				}
				break;
			case 2:
				if(quEmpty(waitingqueue_de)){
					printf("������Ҫ��վ�ĳ��ƺ��룺");
					scanf("%d",&number);
					if(departure(parkingspace,waitingqueue_de,number)){
						if(!quEmpty0(waitingqueue_en)){
							defaultInit(car);
							deQueue(waitingqueue_en,car);
							while(!data_position||!data_time){
								printf("��ǰ���ƺ���Ϊ %d ��������Ҫ��վͣ��\n�������볡ͣ����λ�ã�����Ϊ��ǰ�ճ�λ����",car.number);
								scanf("%d",&position);
								printf("�����뵽��ʱ�䣨�밴��ʽ����������Ը���\n���������ʽ   Сʱ������    \nð��ӦΪ�������뷨�µ�ð�ţ���");
								scanf("%d��%d",&arrive_hour,&arrive_minute);
								data_position=setPosition(car,position);
								data_time=setArrivetime(car,arrive_hour,arrive_minute);
								if(!data_position||!data_time){
									printf("����������������ϸ��������ʽ��\n");
								}
							}
					data_position=false;
					data_time=false;
					parking(parkingspace,car,position);
						}
					}
					else{
						printf("������ĳ��ƺ��벻��ͣ�����ڣ�");
					}
				}
				else{
					printf("��վ����������������ȡ���ã�");
				}
				break;
			case 3:
				if(!quEmpty0(waitingqueue_de)){
					defaultInit(car);
					deQueue(waitingqueue_de,car);
					printf("$��ǰ���ƺ���Ϊ %d ��������Ҫ�Ʒѳ�վ",car.number);
					printf("����������ʱ�䣨�밴��ʽ����������Ը���\n���������ʽ   Сʱ������    \nð��ӦΪ�������뷨�µ�ð�ţ���");
					scanf("%d��%d",&hour,&minute);
					sum=((hour-car.arrive_hour)*6000+(minute-car.arrive_minute)*100)/(60/B);
					while(hour<car.arrive_hour||hour==car.arrive_hour&&minute<car.arrive_minute){
						if(hour<car.arrive_hour||hour==car.arrive_hour&&minute<car.arrive_minute){
							printf("����������ȷ��ʱ�䣡");
							scanf("%d��%d",&hour,&minute);
						}
						sum=((hour-car.arrive_hour)*6000+(minute-car.arrive_minute)*100)/(60/B);
					}
					printf("$���շѣ�%2.4fԪ",sum/100);	
				}
				else{
					printf("����ǰ��Ҫ��վ������");
				}
				break;
			case 4:
				printf("ллʹ�ã�"); 
				run=false;
				break;
			default:
				printf("���󣡣���������ȷ�Ĺ�����š�\n");
				break;
		}
	}
	return 0;
}
