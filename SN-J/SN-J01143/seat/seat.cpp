//SN-J01143  韩世宇辰  西安辅轮中学  
#include<bits/stdc++.h>
using namespace std;
double y;
int x,n,m,d[110],z;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>d[i];
	}
	x=d[1];
	sort(d+1,d+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(x==d[i]){
			y=i;
			break;
		}
	}
	z=ceil((y*1.0)/(n*1.0));
	cout<<z<<" ";
	if(y/n==1){
		cout<<n;
	}else{
		cout<<ceil(y/n);
	}
	
	
	
	return 0;
}

