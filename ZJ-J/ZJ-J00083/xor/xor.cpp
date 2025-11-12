#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}g[10000000];
int cmp(node a,node b){
	return a.r<b.r||a.r==b.r&&a.l>b.l;
}
int n,k,x,s[500010],cnt,f[10000000],MAX,a[500010],bo,ans;
vector<int>v[2097152];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	v[0].push_back(0);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]>1)bo=1;
		s[i]=s[i-1]^a[i];
		v[s[i]].push_back(i);
	}
	if(!bo){
		if(!k){
			ans=0;
			for(int i=1;i<=n;++i)
			if(!a[i])++ans;
			else if(a[i]==1&&a[i+1]==1){
				++ans;
				++i;
			}
			cout<<ans<<"\n";
		}
		if(k==1){
			for(int i=1;i<=n;++i)
			if(a[i]==1)++ans;
			cout<<ans<<"\n";
		}
		if(k>1)cout<<"0\n";
		return 0;
	}
	for(int i=1;i<=n;++i){
		x=s[i]^k;
		for(int j=0;j<v[x].size();++j)
		if(v[x][j]+1>i)break;
		else g[++cnt]={v[x][j]+1,i};
	}
	sort(g+1,g+cnt+1,cmp);
	for(int i=1;i<=cnt;++i){
		f[i]=1;
		for(int j=1;j<i;++j)if(g[i].l>g[j].r)f[i]=max(f[i],f[j]+1);
	}
	for(int i=1;i<=cnt;++i)MAX=max(MAX,f[i]);
	cout<<MAX<<"\n";
	return 0;
}
