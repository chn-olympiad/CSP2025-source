#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5007;
const int Mod=998244353;
int n;
int cnt;
int a[N];
struct Node{
	int maxx;
	int sum;
	int num;
};
vector<Node> tot;
void dfs(int id,int maxx,int sum,int num){
	if(id==n){
		Node a;
		a.maxx=maxx;
		a.num=num;
		a.sum=sum;
		for(int i=0;i<tot.size();++i){
			if(a.maxx==tot[i].maxx && a.num==tot[i].num && a.sum==tot[i].sum)return;
		}
		if(sum>2*maxx && num>=3){
			++cnt;
			tot.push_back(a);
		}
		return;
	}
	for(int i=id+1;i<=n;++i){
		dfs(i,a[i],sum+a[i],num+1);
		dfs(i,maxx,sum,num);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		dfs(i,a[i],a[i],1);
	}
	cout<<cnt%Mod;
	return 0;
}
