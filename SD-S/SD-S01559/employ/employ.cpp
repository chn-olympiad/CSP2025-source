#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e2+10;
const ll Pmod=998244353;
ll s[N],c[N],tc[N],p[N],n,m,ans;
char chr;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=n;i++){
		cin>>chr;
		s[i]=(chr-'0');
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	do{
		for(int i=1;i<=n;i++) tc[i]=c[p[i]];
		ll lse=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(lse>=tc[i]||!s[i]){
				lse++; 
			}else cnt++;
		}
		ans+=(cnt>=m);
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<endl;
	return 0;
}
