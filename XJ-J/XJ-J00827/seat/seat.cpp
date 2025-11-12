#include<bits/stdc++.h>
using namespace std;
const int N=11,M=11;
int u[N*M];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>u[i];
	}
	int R=u[1];
	sort(u+1,u+1+n*m,cmp);
	int fi=1;
	while(u[fi]!=R){
		fi++;
	}
	int a=ceil((fi*1.0)/(n*1.0)),b=fi%n;
	if(a%2==0){
		if(b==0){
			b=1;
		}else{
			b=n-(b-1);
		}
	}else{
		if(b==0){
			b=n;
		}
	}
	cout<<a<<' '<<b;
	return 0;
}
