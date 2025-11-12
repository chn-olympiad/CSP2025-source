#include<bits/stdc++.h>
using namespace std;
string ss;
long long a[505],s[505],n,m,b[505],ans,f[505],x,sn;
void find(int now,int pre,int time){
	if(pre==m){
		long long anss=1;
		for(int i=1;i<=n-pre-time;i++)anss=(anss*i)%998244353;
		ans=(ans+anss)%998244353;
	}
	else if(now<=n){
		for(int i=1;i<=n;i++){
			if(s[now]==1 and time<b[i] and f[i]!=1){
				f[i]=1;
				find(now+1,pre+1,time);
				f[i]=0;
			}
			else if((s[now]==0 and f[i]!=1) or(time>=b[i] and f[i]!=1)){
				f[i]=1;
				find(now+1,pre,time+1);
				f[i]=0;
			}
		}
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>ss;
	for(int i=1;i<=n;i++){
		s[i]=int(ss[i-1])-48;
		sn=sn+1-s[i];
	}
	for(int i=1;i<=n;i++){cin>>x;a[x]++;b[i]=x;}
	for(int i=1;i<=n;i++)a[i]=a[i-1]+a[i];
	if(sn==0){
		ans=1;
		for(int i=1;i<=n;i++)ans=(ans*i)%998244353;
		cout<<ans%998244353;
	}
	else if(n-sn<m){
		cout<<"0";
	}
	else if(m==1){
		long long nn,p=0,k=1,ans=0;
		if(s[1]==1){
			p++;
			nn=n-a[0];
			long long anss=1;
			for(int j=1;j<=n-p;j++)anss=(anss*j)%998244353;
			ans=(ans+(k*nn*anss)%998244353)%998244353;
			k*=a[0];
		}
		for(int i=2;i<=n;i++){
			if(s[i]==1){
				p++;
				nn=n-a[i-1];
				long long anss=1;
				for(int j=1;j<=n-p;j++)anss=(anss*j)%998244353;
				ans=(ans+k*nn*anss)%998244353;
				k=(k*a[i-1])%998244353;
			}
		}
		cout<<ans%998244353;
	}
	else{
		find(1,0,0);
		cout<<ans%998244353;
	}
	return 0;
}
