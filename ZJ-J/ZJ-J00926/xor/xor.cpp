#include<bits/stdc++.h>
using namespace std;

long long a[100005],n,k,cnt,ans,rd[100005],maxs,len[100005],usd[100005];
bool sm[100005];
vector< pair<int,int> > v;
vector<int>g[100005];
stack<int>s;
bool cmp(pair<int,int> x,pair<int,int> y){
	if(x.first==y.first)return x.second<y.second;
	else return x.first<y.first;
}
void dfs(int x,long long num){
	ans=max(ans,num+1);
	if(x>=cnt-1)return;
	for(int i=x+1;i<cnt;i++){
		if(usd[i])continue;
		dfs(i,num);
	}
	for(int i=0;i<g[x].size();i++)usd[g[x][i]]=true;
	for(int i=x+1;i<cnt;i++){
		if(usd[i])continue;
		dfs(i,num+1);
	}
	for(int i=0;i<g[x].size();i++)usd[g[x][i]]=false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0||(a[i-1]==1&&usd[i-1]==false))ans++,usd[i]=true;
		}
		if(ans==0)cout<<n/2;
		else cout<<ans;
		return 0;
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==1)ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i] xor a[i-1];
		for(int j=1;j<=i;j++)if((a[j-1] xor a[i] )==k)v.push_back({j,i}),cnt++;
	}
	sort(v.begin(),v.begin()+cnt,cmp);
	for(int i=0;i<cnt-1;i++)
		for(int j=i+1;j<cnt;j++)
			if(v[i].second>=v[j].first)g[i].push_back(j);
	dfs(0,0);
	cout<<ans<<"\n";
	return 0;
}
