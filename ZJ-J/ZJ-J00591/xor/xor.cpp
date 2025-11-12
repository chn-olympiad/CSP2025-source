#include<bits/stdc++.h>
using namespace std;
int n,k,fl,sum,a[500005],ans,ti,m[10005],sz[10005],ma,f[1005][1005],q[10005];
struct Node{
	int l,r;
}s[10005];
int yh(int a,int b){
	int x=1,ans=0;;
	while(a>0||b>0){
		if((a&1)==(b&1)){
			if(a/2!=0||b/2!=0)
				x=x*2;
		}
		else ans+=x,x*=2;
		a/=2,b/=2;
	}
	return ans;
}
int pd(){
	memset(sz,0,sizeof(sz));
	for(int i=1;i<=ti;i++)
		if(m[i]==1){
			if(s[i].l==s[i].r)sz[s[i].l]=-2e9;
			else sz[s[i].l]=i,sz[s[i].r]=i;
		}
	int t=0;
	for(int i=1;i<=1005;i++){
		if(sz[i]==-2e9){
			if(t==0)continue;
			else return 0;
		}
		if(t==0&&sz[i]!=0){t=sz[i];continue;}
		if(sz[i]!=0&&t!=sz[i])return 0;
		if(sz[i]!=0&&t==sz[i])t=0;
	}
	return 1;
}
void sc(int t,int sl){
	if(t>ti){
		if(pd())ma=max(ma,sl);
		return ;
	}
	m[t]=1;
	sc(t+1,sl+1);
	m[t]=0;
	sc(t+1,sl);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w".stdout);
	cin>>n>>k;fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)fl=0;
		if(a[i]==0||a[i]==1)sum++;
	}
	if(fl==1){
		if(k==0){
			cout<<n/2;
			return 0;
		}
		if(k==1){
			cout<<n;
			return 0;
		}
	}
	if(sum==n){
		if(k==1){
			ans=0;
			for(int i=1;i<=n;i++)
				if(a[i]==1)ans++;
			cout<<ans;return 0;
		}
		if(k==0){
			ans=0;
			for(int i=1;i<=n;i++)
				if(a[i]==0)ans++;
			for(int i=1;i<=n;i++)
				if(a[i]==1&&a[i+1]==1)ans++,a[i+1]=0;
			cout<<ans;return 0;
		}
	}
	q[1]=a[1];
	for(int i=2;i<=n;i++)
		q[i]=yh(q[i-1],a[i]);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			f[i][j]=yh(q[j],q[i-1]);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(f[i][j]==k)s[++ti].l=i,s[ti].r=j;
	sc(1,0);
	cout<<ma;
	return 0;
}

