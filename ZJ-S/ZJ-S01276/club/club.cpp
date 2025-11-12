#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,i,j,flag,flag1,sum,b[100010],c[100010],a[100010][5];
void dfs(int x,int cnt1,int cnt2,int cnt3){
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2) return;
	if(x==n+1){
		int i,ans=0;
		for(i=1;i<=n;i++) ans+=a[i][c[i]];
		sum=max(sum,ans);
		return;
	}
	c[x]=1;
	dfs(x+1,cnt1+1,cnt2,cnt3);
	c[x]=2;
	dfs(x+1,cnt1,cnt2+1,cnt3);
	c[x]=3;
	dfs(x+1,cnt1,cnt2,cnt3+1);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		flag=flag1=sum=0;
		for(i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) flag=1;
			if(a[i][3]!=0) flag1=1;
		}
		if(!flag){
			for(i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+n+1);
			for(i=n;i>=n/2+1;i--) sum+=b[i];
			cout<<sum<<"\n";
			continue;
		}
		if(!flag1){
			int cnt=0;
			for(i=1;i<=n;i++) b[++cnt]=a[i][2]-a[i][1],sum+=a[i][1];
			sort(b+1,b+cnt+1);
			for(i=n;i>=n/2+1;i--) sum+=b[i];
			cout<<sum<<"\n";
			continue;
		}
		if(n<=30){
			dfs(1,0,0,0);
			cout<<sum<<"\n";
			continue;
		}
		for(i=1;i<=n;i++) sum+=max(a[i][1],max(a[i][2],a[i][3]));
		cout<<sum<<"\n";
	}
}
