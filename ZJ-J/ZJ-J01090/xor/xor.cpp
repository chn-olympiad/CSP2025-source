#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[500010];
struct node{
	int s,e;
};
vector<node> c;
bool cmp(node x,node y){
	if(x.e==y.e){
		return x.s>y.s;
	}
	return x.e<y.e;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	unordered_map<int,int>mp;
	for(int i=n-1;i>=1;i--){
		b[i]=a[i]^b[i+1];
	}
	for(int i=1;i<=n;++i){
		mp[b[i]]=i;
	}
	for(int i=n;i>=1;i--){
		if(mp.count(a[i]^m)&&mp[a[i]^m]<=i){
			c.push_back({mp[a[i]^m],i});
		}
		m^=a[i-1];
	}
	sort(c.begin(),c.end(),cmp);
	int ans=0,s=0;
	for(int i=0;i<c.size();++i){
		if(s<c[i].s){
			s=c[i].e;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}