#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int p=a[1];
	sort(a+1,a+n*m+1,cmp);
	int th;
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			th=i;
			break;
		}
	}
	int op;
	if(int(ceil(th*1.0/n))%2==1){
		op=(th-1)%n+1;
	}
	else{
		op=n-(th-1)%n;
	}
	cout<<ceil(th*1.0/n)<<' '<<op;
	return 0;
}

