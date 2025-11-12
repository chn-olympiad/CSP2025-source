#include<bits/stdc++.h>
using namespace std;
int a[100010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sr,sp;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sr=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(sr==a[i]){
			sp=i;
		}
	}
	int l=(sp-1)/n+1;
	int lp=1;
	for(int i=(l-1)*n+1;i<=l*n;i++){
		if(sr==a[i]){
			break;
		}
		lp++;
	}
	if(l%2==0){
		cout<<l<<' '<<n-lp+1;
	}
	else{
		cout<<l<<' '<<lp;
	}
	return 0;
}

