/*
弄不死就往死里弄！
不要放弃任何一点分！
先写暴力！发掘特殊性质！
读题读题读题！
int <-> long long 数组大小！ MLE?RE?
图论？DP？
优化一下？
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=18;
const int Mod=998244353;

int diffi[N];
int n,m;
int c[N];
int p[N];
int yankk[N];
bool kls=false;
int equal0;

void readin() {
	cin>>n>>m;
	string s;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;++i) {
		diffi[i]=s[i]-'0';
		if(diffi[i]==0) kls=1;
	}
	for(int i=1;i<=n;++i) {
		cin>>c[i];
		if(c[i]==0) equal0++;
	}
} 

void solve() {
	for(int i=1;i<=n;++i) {
		p[i]=i;
	}
	int ans=0;
	do{
		for(int i=1;i<=n;++i) {
			yankk[i]=c[p[i]];//人数打乱顺序 
		}
		int go_away=0,used=0;
		for(int i=1;i<=n;++i) {
			if(go_away>=yankk[i]) {
				go_away++;
			}
			else {
				if(diffi[i]==0) go_away++;
				else used++;
			}
			if(used>=m) {
				ans++;
				ans%=Mod;
				break;
			}
		}
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<"\n";
}


signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	readin();
//	if(kls)
	solve();
////	else {
//		int res=1;
//		for(int i=n;i>=1;--i) {
//			res=(__int128)res*i%Mod;
//		}	
//		cout<<res<<"\n";
////	}	
	return 0;
}
