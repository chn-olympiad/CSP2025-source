#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,ans;
long long k,a[maxn],pre[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		pre[i]=pre[i-1]^a[i];
	}
	int left=1;
	for(int j=1;j<=n;j++){
		for(int i=left;i<=j;i++){
			if((pre[j]^pre[i-1])==k){//Çø¼ä [i, j] , xor[i,j]=pre[j]^pre[i-1]
//				cout << "use " << i << ' ' << j << ' ' << (pre[j]^pre[i-1]) << '\n';
				ans++;
				left=j+1;
				break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
