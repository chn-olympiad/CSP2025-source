#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int a[maxn],s[maxn],n,k,t[maxn],l,r,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	s[0]=0;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		s[i]=s[i-1]^a[i];
		//cout << s[i];
	}
	for (int i = 1;i <= n;i++){
		t[i]=-1;
		for (int j = i;j <= n;j++){
			if ((s[j]^s[i-1]) == k){
				//cout << j << " " << i-1 << "\n";
				t[i] = j;
				break;
			}
		}
	}
	l = t[1],r=t[1],ans=1;
	for (int i = 2;i <= n;i++){
		//cout << t[i];
		if (t[i]==-1) continue;
		if (t[i] < r){
			r = t[i];
		}
		else if (i > r){
			ans++;
			r = t[i];
			//cout << r;
		}
	}
	cout << ans;
	return 0;
}
