#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,c[200010],ans,sum,f[200010],b[200010];
char a[200010];
void dfs(int t){
	int i;
	if(t>n){
		int F=0,ans=0;
		for(i=1;i<=n;i++)
			if(a[i]=='0'||F>=c[b[i]])F++;
			else ans++;
		if(ans>=m)sum++;
		return ;
	}
	for(i=1;i<=n;i++)
		if(f[i]==0){
			f[i]=1;
			b[t]=i;
			dfs(t+1);
			f[i]=0;
		}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a+1;
	for(i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)i--,n--;
	}
	if(n<=10){
		dfs(1);
		cout<<sum;
	}
	else{
		int p=0;
		for(i=1;i<=n;i++)p+=c[i];
		if(m==1){
			if(p==0)return cout<<0,0;
			sum=1;
			for(i=n;i>=1;i--)
				sum=sum*i%998244353;
			cout<<sum<<"\n";
			return 0;
		}
		if(m==n&&p<n)return cout<<0,0;
		if(p==n){
			sum=1;
			for(i=n;i>=1;i--)
				sum=sum*i%998244353;
			cout<<sum<<"\n";
		}
		
	}
}
