#include<iostream>
#define int long long
using namespace std;
const int N=2*1e5+4;
struct edge{
	string s1,s2;
}num[N];
struct que{
	string t1,t2;
}qu[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>num[i].s1>>num[i].s2;
	for(int i=1;i<=q;i++){
		cin>>qu[i].t1>>qu[i].t2;
		int ans=0;
		/*
		What can I say??
		My about????
		*/
		cout<<ans;
	}
	return 0;
}