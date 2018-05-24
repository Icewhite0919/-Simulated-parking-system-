typedef struct{
	int position; //停车位置 
	int number; //车牌号码 
	int arrive_hour; //到达时间_小时 
	int arrive_minute; //到达时间_分钟 
}Data;
//定义车的数据模型
bool setPosition(Data &D,int position){
	if(position>=110&&position<=116){
		D.position=position;
		return true;
	}
	else{
		return false;
	}
}
//输入停车位置
void setNumber(Data &D,int number){
		D.number=number;
}
//输入车牌号码 
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
//设置到达时间 
void defaultInit(Data &D){
	D.position=0;
	D.number=-1;
	D.arrive_hour=0;
	D.arrive_minute=0;
}
//默认设置
