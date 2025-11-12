#include<bits/stdc++.h>
using namespace std;
const int m=998244353;
bool vis[6000][11454];
int l[114514],ans;
vector<int> v;
int n;
void dfs(int p,int maxn,int num){
	if(p>=3&&num>maxn*2){
		ans++;
		ans%=m;
	}
	if(p>=n) return;
	int ll=l[n-1]-l[p-1];
	dfs(p+1,max(maxn,v[p]),num+v[p]);
	dfs(p+1,maxn,num);
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n;i++){
		l[i]=l[i-1]+v[i];
	}
	dfs(1,v[0],v[0]);
	cout<<ans;
}
