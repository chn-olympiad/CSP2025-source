#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,a[N];
string s;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=10){
		int ans=0,p[15]={0};
		for(int i=1;i<=n;i++) p[i]=i;
		do{
			int cntok=0,cntfail=0;
			for(int i=1;i<=n;i++){
				if(cntfail>=a[p[i]])  {
					cntfail++;
					continue;
				}
				if(s[i]=='0'){
					cntfail++;
					continue;
				}
				cntok++;
			}
			if(cntok>=m) ans++;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
}

