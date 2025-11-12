#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][100];
int used[100];
int maxres=0;
vector<int> k;
vector<int> res;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x,int cnt){
	if(x>n){
		maxres=max(maxres,cnt);
		return ;
	}
	for(int i=1;i<=3;i++){
		used[i]++;
		k.push_back(i);
		if(used[i]<=n/2) dfs(x+1,cnt+a[x][i]);
		used[i]--;
		k.pop_back();
	}
}
void solve(){
	cin>>n;
	bool flag2=1,flag3=1;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]) flag2=0;
		if(a[i][3]) flag3=0;
	}
	if(flag2 and flag3){
		vector<int> asd(1);
		for(int i=1;i<=n;i++){
			asd.push_back(a[i][1]);
		}sort(asd.begin(),asd.end(),cmp);
		int res=0;
		for(int i=0;i<n/2;i++){
			res+=asd[i];
		}cout<<res<<'\n';
		return ;
	}
	maxres=0;
	dfs(1,0);
	cout<<maxres<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--) solve();
	return 0;
}
