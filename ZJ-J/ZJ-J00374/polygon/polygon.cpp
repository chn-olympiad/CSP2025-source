#include<bits/stdc++.h>
#define N 5005
using namespace std;
int a[N],n,cnt,mod=998244353,sum;
void dfs(int x,int ma,int su,int cn){
	if(x>n){
		if(cn>=3&&ma*2<su)cnt++;
		return;
	}
	dfs(x+1,ma,su,cn);
	dfs(x+1,max(ma,a[x]),su+a[x],cn+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	if(n<=20)dfs(1,0,0,0);
	else{
		for(int i=3;i<=n;i++){
			long long l=1,res=1;
			for(int j=n;j>i;j--){
				if(j%l==0&&l<=i)res=((j/l)*res)%mod,l++;
				else res=(res*j)%mod;
			}
			cnt=(cnt+res)%mod;
		}
	}
	cout<<cnt%mod;
	return 0;
}