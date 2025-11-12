#include<bits/stdc++.h>
using namespace std;
int n,m,len,x,y,flag,num,pos,a[1050];
inline int read(){
	int x=0,sign=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		sign=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*sign;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();m=read();
	len=n*m;
	for(int i=1;i<=len;i++)a[i]=read();
	pos=a[1];
	sort(a+1,a+len+1,greater<int>());
	x=1;y=1;num=1;flag=1;
	while(y<=m){
		if(flag=1){
			while(x<=n){
				//cout<<y<<','<<x<<' '<<num<<'\n';
				if(pos==a[num]){
					cout<<y<<' '<<x;
					return 0;
				}
				x++;
				num++;
			}
			flag=-1;
			y++;
		}
		if(y>m)break;
		if(flag=-1){
			while(x>=2){
				x--;
				//cout<<y<<','<<x<<' '<<num<<'\n';
				if(pos==a[num]){
					cout<<y<<' '<<x;
					return 0;
				}
				num++;
			}
			flag=1;
			y++;
		}
		if(y>m)break;
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
3 1
*/