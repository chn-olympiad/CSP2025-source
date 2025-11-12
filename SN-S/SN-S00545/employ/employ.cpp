#include <bits/stdc++.h>
using namespace std;
const int maxn=550;
int n,m;
string s;
int c[maxn],pos[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) pos[i]=i;
	long long ans=0;
	do{
		int f=0,q=0;
		for(int i=1;i<=n;i++) {
			if(f>=c[pos[i]]){
				f++;
				continue;
			}
			if(s[i]=='0') {
				f++;
				continue;
			}
			q++;
			if(q>=m) {
				ans++;
				break;
			}
		} 
	}
	while(next_permutation(pos+1,pos+1+n));
	cout<<ans<<"\n";
	return 0;
}
