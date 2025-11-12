#include<bits/stdc++.h>
using namespace std;

int now,ans,jilu[500005],top;

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		jilu[top++]=0;
		for(int j = 0; j < top; j++) {
			jilu[j] ^= a;
			if(jilu[j]==k) {
				ans++;
				top = 0;
				break;
			}
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}