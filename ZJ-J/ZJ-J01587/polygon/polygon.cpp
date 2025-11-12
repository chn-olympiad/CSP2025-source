#include<bits/stdc++.h>
using namespace std;
int n;
const long long MOD=998244353;
int a[5005]={};
long long cnt=0,t=1,y;
int c(int x,int y){
	int xy=1;
	int xx=1;
	for(int i=1;i<=x;++i){
		xy*=(y-i+1)%MOD;
		xx*=(x-i+1)%MOD;
	}
	return xy/xx;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxx=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx==1){
		for(int i=3;i<=n;++i){
			cnt=(cnt+c(i,n))%MOD;
		}
		cout<<cnt;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n<=3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

