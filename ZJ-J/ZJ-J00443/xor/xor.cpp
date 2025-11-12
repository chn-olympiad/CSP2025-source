#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans = 0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	if(k==1){
		for(int i=1;i<=n;i++) if(a[i]==1) ans++;
	}
	if(k==0){
		bool flag = false;
		int cnt = 0;
		for(int i=1;i<=n;i++) if(a[i]==0) ans++;
		for(int i=1;i<=n;i++){
			if(a[i]==1&&flag) cnt++;
			if(a[i]==1&&!flag){
				ans+=cnt/2;
				cnt = 1;
				flag = true;
			}
			if(a[i]==0) flag = false;
		}
		ans+=cnt/2;
	}
	cout << ans;
	return 0;
}
