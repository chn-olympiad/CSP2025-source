#include <bits/stdc++.h>
using namespace std;
long long n,ans,a[5010],kmp[5010],sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	} 
	sort(a+1,a+n+1);
	for(int len = 3;len <= n;len++){
		memset(kmp,0,sizeof(kmp));
		for(int j = 1;j <= len;j++){
			kmp[j] = a[j];
			sum+=kmp[j];
		}
		int tmp = 0;
		for(int i = len;i <= n;i++){
			if(sum > kmp[len]){
				ans++;
				ans %= 998224353;
			}
			if(i<n){
				kmp[(tmp%len)+1] = a[i+1];
			}
			else {
				tmp++;
			}
		}
	} 
	cout << ans;
	return 0;
}
