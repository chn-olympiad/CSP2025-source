#include <bits/stdc++.h>
using namespace std;
long long n,k;
int ans;
int t;
long long f[1010][1010];
int vis[1010];
vector<int>  v;
int check(int x, int y){
	for(int i=x;i<=x+y;i++){
		if(vis[i]==1) return 0;
	}
	return 1;
}
long long ab(long long x, long long y){
	return x^y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> f[i][0];
	for(int i=1;i<=n;i++){
		for(int j=1;j+i<=n;j++){
			f[j][i]=ab(f[j][0],f[j+1][i-1]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j+i<=n;j++){
			if(f[j][i]==k&&check(j,i)){
				ans++;
				for(int d=j;d<=j+i;d++){
					vis[d]=1;
				}
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
