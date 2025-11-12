#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[1001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nm=n*m;
	int o;
	
	for(int i=1;i<=nm;i++){
		cin>>a[i];
	}
	o=a[1];
	sort(a+1,a+nm+1,cmp);
	int seat;
	for(int i=1;i<=nm;i++){
		if(a[i]==o)seat=i;
	}
	int x=0,y=1,num=1;
	for(int i=1;i<=nm;i++){
		x+=num;
		if(x==n+1){
			num=-1;
			x+=num;
			y++;	
		}
		else if(x==0){
			num=1;
			x+=num;
			y++;
		}
		if(seat==i){
			cout<<y<<' '<<x;
			break;
		}
	}
	return 0;
} 
