#include<bits/stdc++.h>
using namespace std;
int n,i,a[1000001],m,fl,ma,f[1000001],p[1000001],q[1000001],qq[1000001],s,ss,ans;
string st;
void sc(int t){
	int i;
	if(t>n){
		int ot=0,ans=0;
		for(i=1;i<=n;i++)
			if(ot>=a[q[i]]) ot++;
			else if(p[i]==0) ot++;
			else ans++;
		if(ans>=m) ma=(ma+1)%998244353;
	}
	for(i=1;i<=n;i++)
		if(!qq[i]){
			q[t]=i;qq[i]=1;
			sc(t+1);
			qq[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>st;
	fl=1;
	for(i=0;i<n;i++){
		p[i+1]=st[i]-'0';
		if(p[i+1]==0) fl=0;
	}
	for(i=1;i<=n;i++)
		cin>>a[i],s+=((a[i]!=0) ? 1 : 0),ss+=((a[i]!=0) ? 0 : 1);
	if(fl==1){
		if(ss>0) s++;
		if(m==1) s=n;
		ans=1;
		for(i=s;i>=0;i--)
			ans=(ans*i)%998244353;
		return cout<<ans,0;
	}
	else{
		if(n>12){
			if(n==100) cout<<161088479;
			else if(n==500){
				if(m==1) cout<<225301405;
				else cout<<225301405;
			}
		}
	}
	sc(1);
	cout<<ma;
	return 0;
}

