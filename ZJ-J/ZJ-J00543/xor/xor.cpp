#include<bits/stdc++.h>
using namespace std;
int n,ant;
int k,s[500010];
int f[500010];
struct node{
	int l,r;
}b[500010];
map<int,set<int> > mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		s[i]=s[i-1]^a;
		mp[s[i]].insert(i);
	}
	int ant=0;
	for(int i=1;i<=n;i++){
		int ne=(s[i-1]^k);
		auto zxj=(mp[ne].lower_bound(i));
		if(zxj!=mp[ne].end()){
			b[++ant]={i,*zxj};
		}
	}
	int ans=0,maxx=0;
	for(int i=1;i<=ant;i++){
		f[b[i].r]=max(f[b[i].r],maxx+1);
		ans=max(ans,f[b[i].r]);
		for(int j=b[i].l;j<b[i+1].l;j++){
			maxx=max(maxx,f[j]);
		}
	}
	cout<<ans;
	return 0;
}
