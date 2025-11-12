#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define ll long long
#define itn int
#define int ll
using namespace std;
const int MOD1=1e9+7;
const int MOD2=998244353;
const int N=5e2+5;
int n,m,ans,c[N],p[N];
string s;
void Solve(){
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n==m){
		string t="";
		for(int i=1;i<=n;i++)
			t+="1";
		if(s!=t){
			cout<<0;
			return;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			cnt+=(c[i]!=0?1:0);
		if(cnt!=n){
			cout<<0;
			return;
		}
		int res=1;
		for(int i=1;i<=n;i++)
			res=res*i%MOD2;
		cout<<res;
		return;
	}
	for(int i=1;i<=n;i++)
		p[i]=i;
	do{
		int r=0,k=0;
		for(int i=1;i<=n;i++){
			if(r>=c[p[i]]){
				r++;
				continue;
			}
			if(s[i-1]=='1')k++;
			else r++;
		}
		if(k>=m)ans++,ans%=MOD2;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--)
		Solve();
	return 0;
}
