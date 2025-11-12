#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const ll MAXN=11;
ll n,m,demand[MAXN],ord[MAXN]={0,1,2,3,4,5,6,7,8,9,10},ans,cnt,cnt2;
string s;
bool f[MAXN];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		f[i]=(s[i]!='0');
		cnt+=f[i];
		cin>>demand[i];
		if(demand[i]>0)cnt2++;
	}
	if(cnt2<m){
		cout<<0;
		return 0;
	}
	if(n<=10){
		while(next_permutation(ord,ord+n)){
			ll td=0;
			for(int i=0;i<n;i++){
				if(f[ord[i]]==0||td>=demand[ord[i]]){
					td++;
				}
			}
			if(td+m<=n)ans++;
		}
		cout<<ans;
	}else if(cnt==n){
		ans=1;
		for(int i=1;i<=cnt;i++){
			ans*=i;
			ans%=mod;
		}
	}
	return 0;
}
