#include<stdio.h>
#include<time.h>
int b_time(int bd,int bm,int by){
	time_t t;
	struct tm* current_time;
	t = time(NULL);
	current_time=localtime(&t);
	int m,d,find_day,y,find_year,total_day,h,find_time;
	
	d = current_time->tm_mday;
		find_day = d-bd;
	y=current_time->tm_year+1900;
		find_year=y-by;
	total_day=find_year*365;
		h=current_time->tm_hour;
		find_time = total_day*24+h;
	return find_time;
}
int b_year(int bd,int bm,int by){
	time_t t;
	struct tm* current_time;
	t = time(NULL);
	current_time=localtime(&t);
	int y,find_year;
	y=current_time->tm_year+1900;
		find_year=y-by;
	
	return find_year;
}
int b_day(int bd,int bm,int by){
	time_t t;
	struct tm* current_time;
	t = time(NULL);
	current_time=localtime(&t);
	int d,this_day,y,find_year,find_day,m,this_month,find_month,ld=0,this_year_day,current_day;
	d=current_time->tm_mday;
		this_day = d-bd;
		current_day=30-d +1;
		this_year_day=current_time->tm_yday;
	m=current_time->tm_mon+1;
		this_month=m-bm;
		
	y=current_time->tm_year+1900;
		find_year=y-by;
		find_month=find_year*12;
		
	if(find_year!=0){
		ld=find_year/4;
	}
	else{
		ld=0;
	}

	find_day=find_year*365+ld+current_day;
//	find_day = find_month*30 +ld+this_day;
//	return find_month;
	return find_day;
}
int main(){
	int m,y,d,p,q,r;
//	p=b_time(1,7,2003);
//	q=b_year(1,7,2003);
//	r=b_day(1,7,2003);
	printf("enter your birth day in formate of dd/mm/yyyy= \t");
	scanf("%d\t%d\t%d",&d,&m,&y);
	p=b_time(d,m,y);
	q=b_year(d,m,y);
	r=b_day(d,m,y);
	printf("\t\t\t your enter your birthday = %d:%d:%d\n",d,m,y);
	printf("your birth total hours = %d\n",p);
		printf("your birth total year = %d\n",q);
				printf("your birth total days = %d\n",r);
}
//	printf("this year day %d\n",current_time->tm_yday);
//	printf("this month %d\n",current_time->tm_mon+1);
//	printf("this year %d\n",current_time->tm_year+1900);
//	printf("this time %d:%d:%d",current_time->tm_hour,current_time->tm_min,current_time->tm_sec);

//int month_list[12]={31,28,31,30,31,30,31,31,30,31,30,31};
//	m=current_time->tm_mon+1;
//	for(i=0;i<12;i++){
//		if(m_count<m){
//			count +=i-30;
//			m_count +=1;
//		}
//	}
//	days += count;
