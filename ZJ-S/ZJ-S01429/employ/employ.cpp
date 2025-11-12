#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
const int N=11;
int nex[N],n,c[N],m,hard[N],ans;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		hard[i]=ch-'0';
	}for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		nex[i]=i;
	}
	do{
		int nai=0;
		int ism=0;
		for(int i=1;i<=n;i++){
			if(nai>=c[nex[i]]||hard[i]==0){
				nai++;
			}else{
				ism++;
			}
		}
		if(ism>=m){
			ans++;
		}
		ans%=mod;
	}while(next_permutation(nex+1,nex+n+1));
	cout<<ans;
	return 0;
}
