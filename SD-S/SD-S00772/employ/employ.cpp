#include<bits/stdc++.h>
using namespace std;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	string c;cin>>c;
	for(int i=1;i<=n;i++)cin>>a[i];
		int p[15],ans=0;
		for(int i=1;i<=n;i++)p[i]=i;
		do{
			int pat=0,suc=0;
			for(int i=1;i<=n;i++){
				if(pat>=a[p[i]]||c[i-1]=='0')pat++;
				else suc++;
			}
			if(suc>=m){
				ans++;
			}
		}while(next_permutation(p+1,p+n+1));
		cout<<ans%998244353;
	return 0;
}

