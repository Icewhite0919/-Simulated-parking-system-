typedef struct{
	int position; //ͣ��λ�� 
	int number; //���ƺ��� 
	int arrive_hour; //����ʱ��_Сʱ 
	int arrive_minute; //����ʱ��_���� 
}Data;
//���峵������ģ��
bool setPosition(Data &D,int position){
	if(position>=110&&position<=116){
		D.position=position;
		return true;
	}
	else{
		return false;
	}
}
//����ͣ��λ��
void setNumber(Data &D,int number){
		D.number=number;
}
//���복�ƺ��� 
bool setArrivetime(Data &D,int arrive_hour,int arrive_minute){
	if(arrive_hour>=0&&arrive_hour<24&&arrive_minute>=0&&arrive_minute<60){
		D.arrive_hour=arrive_hour;
		D.arrive_minute=arrive_minute;
		return true;
	}
	else {
		return false;
	}
}
//���õ���ʱ�� 
void defaultInit(Data &D){
	D.position=0;
	D.number=-1;
	D.arrive_hour=0;
	D.arrive_minute=0;
}
//Ĭ������
