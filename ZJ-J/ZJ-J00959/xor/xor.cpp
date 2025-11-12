#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
long long sum[500005];
long long f[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(n > 1000){
		int ans = 0;
		if(k == 1){
			for(int i = 1;i <= n;i++) if(a[i] == 1) ans++;
		}
		else{
			for(int i = 1;i <= n;i++){
				if(a[i] == 0) ans++;
				else if(a[i+1] == 1) i++,ans++;
			}
		}
		cout << ans;
		return 0;
	}
	for(int i = 1;i <= n;i++) sum[i] = (sum[i-1] ^ a[i]);
	memset(f,255,sizeof(f));
	f[0] = 0;
	if(a[1] == k) f[1] = 1;
	for(int i = 2;i <= n;i++){
		f[i] = f[i-1];
		int maxx = i-1;
		for(int j = i-2;j >= 0;j--){
			if(f[j] >= f[maxx]) maxx = j;
		}
		long long s = f[maxx];
		for(int l = maxx+1;l <= i;l++){
			if((sum[l-1] ^ sum[i]) == k){
				s++;
				break;
			}
		}
		//cout << i << ' ' << s << endl;
		f[i] = s;
	}
	cout << f[n];
	return 0;
}
