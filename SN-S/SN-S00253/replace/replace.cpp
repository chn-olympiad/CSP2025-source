// SN-S00253  张笑语  西安高新第一中学
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define ll long long
#define il inline
#define ull unsigned ll
using namespace std;
namespace asbt{
ifstream cin("replace.in");
ofstream cout("replace.out");
const int maxn=2e3+5;
const ull bas=13331;
int n,m,tot,tr[maxn][26];
ull ha[maxn],pw[maxn];
string a,b;
__gnu_pbds::gp_hash_table<ull,int> cnt[maxn];
il void init(int n=2e3){
	pw[0]=1;
	for(int i=1;i<=n;i++){
		pw[i]=pw[i-1]*bas;
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	init();
	while(n--){
		cin>>a>>b;
		int p=0;
		for(char i:a){
			int d=i-'a';
			if(!tr[p][d]){
				tr[p][d]=++tot;
			}
			p=tr[p][d];
		}
		ull ha=0;
		for(char i:b){
			ha=ha*bas+i;
		}
//		cout<<ha<<'\n';
		cnt[p][ha]++;
	}
	while(m--){
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<'\n';
			continue;
		}
		int len=a.size(),l=1,r=len;
		a=" "+a,b=" "+b;
		while(a[l]==b[l]){
			l++;
		}
		while(a[r]==b[r]){
			r--;
		}
//		cout<<l<<' '<<r<<'\n';
		ha[0]=0;
		for(int i=1;i<=len;i++){
			ha[i]=ha[i-1]*bas+b[i];
//			cout<<ha[i]<<' ';
		}
//		for(int i=1;i<=len;i++){
//			for(int j=i;j<=len;j++){
//				cout<<i<<' '<<j<<' '<<ha[j]-ha[i-1]*pw[j-i+1]<<'\n';
//			}
//		}
//		cout<<'\n';
		int ans=0;
		for(int i=1;i<=l;i++){
			int p=0;
			for(int j=i;j<=len;j++){
				int d=a[j]-'a';
				if(!tr[p][d]){
					break;
				}
				p=tr[p][d];
				if(j>=r){
					ans+=cnt[p][ha[j]-ha[i-1]*pw[j-i+1]];
//					cout<<i<<' '<<j<<' '<<p<<' '<<ha[j]-ha[i-1]*pw[j-i+1]<<' '<<ans<<'\n';
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
}
int main(){return asbt::main();}

