#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
const ll N=1e5+100,p=998244353;
ull n,q,mask=478435792,ha1[N],ha2[N];
unordered_map<ull,ull>ma;
string s1,s2,t1,t2;
ull shift(ull x){
	x^=mask;
	x^=x<<11;
	x^=x>>13;
	x^=x<<17;
	x^=mask;
	return x;
}
ull haxi(string qwq){
	ull sum=0;
	for(int i=0;i<qwq.size();i++){
		sum=shift(sum*26+qwq[i]-'a');
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		ma[haxi(s1)]=haxi(s2);
	}
	while(q--){
		cin>>t1>>t2;
		ll ans=0;
		for(int i=0;i<t1.size();i++){
			ha1[i]=shift(t1[i]-'a'),ha2[i]=shift(t2[i]-'a');
			for(int j=i+1;j<t1.size();j++){
				ha1[j]=shift(ha1[j-1]*26+t1[j]-'a');
				ha2[j]=shift(ha2[j-1]*26+t2[j]-'a');
			}
			for(int j=t1.size()-1;j>i;j--){
				if(ma.count(ha1[j])&&ma[ha1[j]]==ha2[j]) ans++;
				if(t1[j]!=t2[j]) break;
			}
			if(t1[i]!=t2[i]) break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
