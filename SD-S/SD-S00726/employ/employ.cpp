#include<bits/stdc++.h>
#define int long long
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int N=5e2+10,P=998244353,Mod=1e9+7;
int n,m,c[N],ans,p[N];
bool flag=1;
string nd;
signed main() {
	FAST
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>nd;
	nd=' '+nd;
	for(int i=1; i<=n; i++)cin>>c[i],p[i]=i,flag=(flag&&(nd[i]-'0'));
	if(n<=10) {
		do {
			int ln=0;
			for(int i=1; i<=n; i++) {
				if(ln>=c[p[i]]||nd[i]=='0')ln++;
//			cout<<ln<<' '<<p[i]<<'\n';
				if(n-ln<m)break;
			}
//		cout<<"---------------------------\n";
			if(n-ln>=m)ans++;
		} while(next_permutation(p+1,p+n+1));
		cout<<ans;
	}
	else if(flag) {
		ans=1;
		for(int i=1; i<=n; i++)ans=ans*i%P;
		cout<<ans;
		return 0;
	}
	return 0;
}
