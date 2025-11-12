#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//输入 
	int n,m;//n行,m列 
	cin>>n;
	cin>>m;//2,2
	int h=n*m;//4
	int a[h+1],b[h+1];
	for(int i=1;i<=h;i++){
		cin>>a[i];//99 100 97 98
	}
	int cj=a[1];//99
	//排序 
	int x=0,y=0,e=1,w=h,c=0;
	int d1=a[1],d2=a[2];
	while(w!=0){
		for(int i=1;i<=h;i++){
			if(a[i]>=d1){
				d1=a[i];
				c=i;
			}
		}
		d2=d1;
		b[e]=d2;
		a[c]=-2;
		d1=-1;
		e++;
		w--;
	}
	//100 99 98 97
	for(int i=1;i<=n;i++){
		if(b[i]==cj){
			e=i;//成绩索引 
		}
	}//2
	//特判
	if(n==1){
		cout<<e-1<<" "<<"1";
		return 0;
	}  
	//列,n=2,m=2
	x=0;
	y=0;
	if(e%n==0){
		x=e/n;//1
	}
	else{
		x=e/n;
	}
	//行
	if(e%2==0){
		y=m-e%n;
	}
	else{
		y=e%n;
		y+=1;
	}
	cout<<x<<" "<<y;
	return 0;
}
/*
2 2
99 100 97 98
1 2

2 2
98 99 100 97
2 2

3 3
94 95 96 97 98 99 100 93 92
3 1

1 4
10 100 99 98
4 1
*/
