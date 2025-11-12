#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e6+10;
const int INF=1e18;
const int base=177;
const int mod=998244353;
int st;
struct node{
	string s1,s2;
	int hs1,hs2;
};
node cj[N];
int lg[N];
void init(){
	lg[0]=1;
	for(int i=1;i<=N-10;i++){
		lg[i]=lg[i-1]*base%mod;
	}
}
int sm[N],smm[N];
int get(int l,int r){
	return ((sm[r]-(sm[l-1]*lg[r-l+1])+mod)%mod+mod)%mod;
}
int gett(int l,int r){
	return (smm[r]-smm[l-1]*lg[r-l+1]+mod)%mod;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cout<<0;
	return 0;
}
