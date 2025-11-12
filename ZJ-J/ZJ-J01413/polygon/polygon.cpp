#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,mod=998244353;
int a[N];
bool check(int l[],int size){//能组成多边形 
	int maxl=0,sum=0;
	for(int i=1;i<=size;i++){
		maxl=max(maxl,l[i]);
		sum+=l[i];
	}
	return sum>2*maxl;
}
int maxl(int l[],int size){
	int maxlength=0,sum=0;
	for(int i=1;i<=size;i++){
		maxlength=max(maxlength,l[i]);
		sum+=l[i];
	}
	return maxlength;
}
int jiecheng(int x){//阶乘 
	if(x==1) 
		return 1;
	return x*jiecheng(x-1);
} 
int C(int n,int m){//组合：n个里面选m个 
	if(n==m)
		return 1;
	if(m>n/2)
		return C(n,n-m);
	return(jiecheng(n)/(jiecheng(m)*jiecheng(n-m)));
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==3){//只有三边 
		ans=check(a,n);
		cout<<ans%mod;
		return 0;
	}
	if(maxl(a,n)==1){
		for(int i=3;i<=n;i++)
			ans+=C(n,i);
		cout<<ans%mod;
		return 0;
	} 
	return 0;
}
