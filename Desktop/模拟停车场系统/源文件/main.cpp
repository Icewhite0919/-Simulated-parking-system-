#include <iostream>
#include <String.h>
#include "SqList.h"
#define B 3//每小时三元 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	int choose;                      //功能序号 
	bool run=true;                   //程序运行状态 
	bool data_position=false;     	 //输入位置合法状态
	bool data_time=false;            //输入时间合法状态 
	Data car;                        //车 
	int position;                    //停车位置 
	int number;                      //车牌号码 
	int arrive_hour;                 //到达时间_小时 
	int arrive_minute;               //到达时间_分钟 
	int hour;                        //现在时间_小时 
	int minute;                      //现在时间_分钟 
	float sum;                       //收费 
	SqList parkingspace;             //车位 
	enter waitingqueue_en;           //入站等候队列 
	departrue waitingqueue_de;       //出站等候队列 
	InitQueue(waitingqueue_en);
	InitQueue(waitingqueue_de);
	int q=17;
	int k=1;
	//定义变量 
	setAllDefault(parkingspace);
	while(run){
		printf("\n当前车位信息：\n");
		Display(parkingspace);
		DisplayQueue_en(waitingqueue_en);
		DisplayQueue_de(waitingqueue_de);
		printf("\n选择功能： 1、入站；\n           2、出站；\n           3、出库汽车计费；\n           4、退出系统\n--------------------------------------------\n");
		scanf("%d",&choose);
		switch(choose){
			case 1:
				if(allparkingspaceEmpty(parkingspace)){
					while(!data_position||!data_time){
						defaultInit(car);
						printf("请输入以下信息：\n");	
						printf("请输入入场停车的位置（必须为当前空车位）：");
						scanf("%d",&position);
						printf("请输入车牌号码（纯数字）：");
						scanf("%d",&number);
						while(q>11){
							for(q=1;q<=17;q++){
								k=k*10;
								if(number/k==0){
									break;
								}
							}
							if(q>11){
								printf("！输入数字超过11位！\n");
								printf("请输入车牌号码（纯数字）：");
								scanf("%d",&number);
							}
						}
						q=17;
						k=1;
						setNumber(car,number);
						printf("到达时间（请按格式输入否则后果自负）\n（！输入格式   小时：分钟    \n冒号应为中文输入法下的冒号）：");
						scanf("%d：%d",&arrive_hour,&arrive_minute);
						data_position=setPosition(car,position);
						data_time=setArrivetime(car,arrive_hour,arrive_minute);
						if(!data_position||!data_time){
							printf("输入数据有误请仔细检查输入格式。\n");
						}
					}
					data_position=false;
					data_time=false;
					parking(parkingspace,car,position);
				}
				else if(!allparkingspaceEmpty(parkingspace)&&quEmpty(waitingqueue_en)){
					defaultInit(car);
					printf("请输入车牌号码（纯数字）：");
					scanf("%d",&number);
					setNumber(car,number);
					enQueue(waitingqueue_en,car);
				}
				else{
					printf("！停车场已满！请找别的停车场停车。");
				}
				break;
			case 2:
				if(quEmpty(waitingqueue_de)){
					printf("请输入要出站的车牌号码：");
					scanf("%d",&number);
					if(departure(parkingspace,waitingqueue_de,number)){
						if(!quEmpty0(waitingqueue_en)){
							defaultInit(car);
							deQueue(waitingqueue_en,car);
							while(!data_position||!data_time){
								printf("当前车牌号码为 %d 的汽车正要进站停车\n请输入入场停车的位置（必须为当前空车位）：",car.number);
								scanf("%d",&position);
								printf("请输入到达时间（请按格式输入否则后果自负）\n（！输入格式   小时：分钟    \n冒号应为中文输入法下的冒号）：");
								scanf("%d：%d",&arrive_hour,&arrive_minute);
								data_position=setPosition(car,position);
								data_time=setArrivetime(car,arrive_hour,arrive_minute);
								if(!data_position||!data_time){
									printf("输入数据有误请仔细检查输入格式。\n");
								}
							}
					data_position=false;
					data_time=false;
					parking(parkingspace,car,position);
						}
					}
					else{
						printf("！输入的车牌号码不在停车场内！");
					}
				}
				else{
					printf("出站队列已满！请先收取费用！");
				}
				break;
			case 3:
				if(!quEmpty0(waitingqueue_de)){
					defaultInit(car);
					deQueue(waitingqueue_de,car);
					printf("$当前车牌号码为 %d 的汽车正要计费出站",car.number);
					printf("请输入现在时间（请按格式输入否则后果自负）\n（！输入格式   小时：分钟    \n冒号应为中文输入法下的冒号）：");
					scanf("%d：%d",&hour,&minute);
					sum=((hour-car.arrive_hour)*6000+(minute-car.arrive_minute)*100)/(60/B);
					while(hour<car.arrive_hour||hour==car.arrive_hour&&minute<car.arrive_minute){
						if(hour<car.arrive_hour||hour==car.arrive_hour&&minute<car.arrive_minute){
							printf("！请输入正确的时间！");
							scanf("%d：%d",&hour,&minute);
						}
						sum=((hour-car.arrive_hour)*6000+(minute-car.arrive_minute)*100)/(60/B);
					}
					printf("$请收费：%2.4f元",sum/100);	
				}
				else{
					printf("！当前无要出站汽车！");
				}
				break;
			case 4:
				printf("谢谢使用！"); 
				run=false;
				break;
			default:
				printf("错误！：请输入正确的功能序号。\n");
				break;
		}
	}
	return 0;
}
