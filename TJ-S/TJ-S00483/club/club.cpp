#include<bits/stdc++.h>
using namespace std;
const int cl =1e5+5;
struct y {
	int a_1;
	int a_2;
	int a_3;
}cy[cl];                                            
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int ans=0,t,n,bx_1,bx_2,bx_3;
	cin >>t;//输入循环数 
	while(t--){
		cin >>n;//输入成员数 
		int cs=n+5;
		for(int i=1;i<=n;i++){
			cin >>cy[i].a_1 >>cy[i].a_2 >>cy[i].a_3;
			bx_1=max(cy[i].a_1,cy[i].a_2);
			bx_2=max(cy[i].a_2,cy[i].a_3);
			bx_3=max(bx_1,bx_2);
			ans+=bx_3;//听天由命计划（部分1） 
		}//输入评价并判断大小 
		cout <<ans;//听天由命计划（部分2） 
	} 
	
	//for(int i=1;i<=n;i++) cout <<cy[i].a_1 <<" " <<cy[i].a_2 <<" " <<cy[i].a_3; //测试用 
	return 0;
}
