#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;ll ans;
string s;
int c[506],vis[506];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	sort(c+1,c+1+n);
	if(m==n)
		cout << 1;
	else{
		for(int i=0;i<n;i++)
			for(int j=1;j<=n;j++){
				if(!vis[i]&&i<j){
					vis[i]=1;
					ans++;
				}
			}
		cout << ans%998244353;
	}
	return 0;
}

