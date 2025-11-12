#include <bits/stdc++.h>
using namespace std;
int n,k;
const int N = 500010,M = 1048600;
int a[N];
int t[M],tag[M];
int main(){	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	int sum = 0,lst = 0,ans = 0;
	t[0]++,tag[0] = 0;
	for(int i = 1;i <= n;i++){
		sum ^= a[i];
//		for(int i = 0;i < 5;i++) cout << t[i] << ' ';
//		cout << endl;
		if(t[sum ^ k] > 0){
			int tmp = (sum ^ k),posl = tag[tmp] + 1;
//			cout << sum << ' ' << k << ' ' << tmp << ' ' << t[tmp] << ' ' << posl << ' ' << i << ' ' << lst << endl;
			if(posl <= lst || posl > i){
				tag[sum] = i;
				t[sum]++;
				continue;
			}
			lst = i,ans++;		
		}
		tag[sum] = i;
		t[sum]++;
	}
	cout << ans << endl;
	return 0;
}
/*
plz 100pts for my xor problem
*/