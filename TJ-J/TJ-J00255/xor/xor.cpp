#include <bits/stdc++.h>
using namespace std;
int n,k,a[500001],s[500001],ans = 0;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d%d",&n,&k,&a[1]);
	s[1] = a[1];
	for (int i = 2; i <= n; i++){
		scanf("%d",&a[i]);
		s[i] = s[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 2; j <= n - i; j++){
			if (s[i + j] - s[i - 1] == k || s[i + j] - s[i - 1] == -k || s[i + j] + s[i - 1] == k){
				ans++;
				i = j + 1;
			}
		}
		if (a[i] == k)
			ans++;
	}
	printf("%d",ans);
	return 0;
}
