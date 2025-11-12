#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*====================*/
const int N = 2e5+10;
/*====================*/
const int INF = 0x3F3F3F3F;
/*====================*/
const int MOD=998244353;
/*====================*/
pair<string,string>a[N];
/*====================*/
void Solve(){
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	while(q--){
		string x,y;cin>>x>>y;
		int ans=0;
		for(int i=1;i<=n;i++){
			int xx=x.find(a[i].first),yy=y.find(a[i].second);
			if(xx!=-1&&yy!=-1&&xx==yy){
				int t=xx+a[i].first.size();
				string s=x.substr(0,xx)+a[i].second+x.substr(t,x.size()-t+1);
				//cout<<x<<' '<<s<<' '<<y<<'\n';
				if(s==y)ans++;
			}
		}cout<<ans<<'\n';
	}
}
/*====================*/
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int T=1;//cin>>T;
	while(T--)Solve();
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
