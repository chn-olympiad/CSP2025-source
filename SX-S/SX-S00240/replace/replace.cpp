#include<bits/stdc++.h>
#define N 5000006
using namespace std;
#define int long long
typedef pair<int,int> pii;
const int p=29;
const int M=998244353;
map<pii,int> cnt;
char s[N],t[N];
int n,q;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	int sum=0;
	for(int i=1;i<=n;++i){
		cin>>(s+1)>>(t+1);
		int h1=0,h2=0,m=strlen(s+1);
		for(int j=1;j<=m;++j){
			h1=(h1*p%M+(s[j]-'a'+1))%M;
			h2=(h2*p%M+(t[j]-'a'+1))%M;
		}
		sum+=m;
		cnt[pii(h1,h2)]++;
	}
	for(int i=1;i<=q;++i){
		cin>>(s+1)>>(t+1);
		int m=strlen(s+1),_m=strlen(t+1);
		if(m!=_m){
			cout<<"0\n";
			continue;
		}
		int L=1,R=m,ans=0;
		while(s[L]==t[L]) ++L;
		while(s[R]==t[R]) --R;
		for(int l=1;l<=L;++l){
			int h1=0,h2=0;
			for(int r=l;r<=m;++r){
				h1=(h1*p%M+(s[r]-'a'+1))%M;
				h2=(h2*p%M+(t[r]-'a'+1))%M;
				if(r>=R) ans+=cnt[pii(h1,h2)];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
