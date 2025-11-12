#include<bits/stdc++.h>
using namespace std;
int n,i,a[100001],ans,mod=998244353,ma,j,x,y;
void sc(int t,int zh,int ma,int g){
	if(t==n+1){
		if(zh>2*ma&&g>=3)ans++;
		return ;
	}
	sc(t+1,zh,ma,g);
	sc(t+1,zh+a[t],ma=max(ma,a[t]),g+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i],ma=max(ma,a[i]);
	sort(a+1,a+1+n);
	if(n<=26){
		sc(1,0,0,0);
		cout<<ans;
	}
	else{
		if(ma==1){
			for(i=3;i<=n;i++){
				x=1;y=1;
				for(j=n-i+1;j<=n;j++)x*=j;
				for(j=1;j<=i;j++)y*=j;
				ans=(ans+x/y)%mod;
			}
			cout<<ans;
		}
		else{
			cout<<mod-1;
		}
	}
}
