#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cr; 
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	cr=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,now=1;
	while(1){
		if(a[now]==cr){
			cout<<y<<' '<<x;
			break;
		}
		++now;
		if((y%2==1 && x==n) || (y%2==0 && x==1)) ++y;
		else{
			if(y%2==1) ++x;
			else --x;
		} 
	}
	return 0;
}
