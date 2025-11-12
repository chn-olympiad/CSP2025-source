#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5001],s=0,b[5001],p=0,x=2,maxn=INT_MIN;
/*bool vis[5001];
void f(int deep,int goal){
	if(deep==goal+1){
		int sum=0;
		sort(b+1,b+1+goal);
		for(int i=1;i<=goal;i++)sum+=b[i];
		if(sum>b[goal]*2){
			s++;	
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			b[deep]=a[i];
			vis[i]=1;
			f(deep+1,goal);
			vis[i]=0;
		}
	}
}*/
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];maxn=max(maxn,a[i]);s+=a[i];
	}
/*	for(int i=3;i<=n;i++){
		s=0,x*=i;
		f(1,i);
		p=p+s/x;
	}
	cout<<p%998244353;*/
	if(n==3&&s>2*maxn)cout<<1;
	else cout<<0;
	return 0;
}
