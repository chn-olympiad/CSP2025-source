
#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;

int n, k, cnt = 0, mx = 0;
int a[N], sum[N];

int dp[N];

namespace subtask1{
	int main(){
		cout<<n/2;
	}
}

namespace subtask2{
	int main(){
		int ans = 0;
		if(k == 1){
			for(int i = 1; i <= n; i++)ans += a[i];
			cout<<ans;
		}else{
			for(int i = 1; i <= n; i++){
				if(a[i] == 1 && a[i+1] == 1)ans++, i++;
				else if(a[i] == 0)ans++;
			}
			cout<<ans;
		}
	}
}

namespace subtask3{
	bool check(int x){
		int l = (sum[n]^(x&1?k:0));
		for(int i = 1; i <= n; i++){
			int k = lower_bound(sum+i, sum+n+1, (l^sum[i-1]))-sum-i;
//			cout<<i<<" "<<k<<endl;
			if(k > i && k <= n)return true;
		}
		return false;
	}
	
	int main(){
		sort(sum+1, sum+n+1);
		int l = 0, r = n;
		while(l < r){
			int mid = l+r >> 1;
			if(check(mid))r = mid;
			else l = mid+1;
		}
		cout<<r;
	}
}



int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	int fg = 1, tg = 1;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		int t = sum[i-1];
		t ^= a[i];
		sum[i] = t;
		fg = (a[i] != 1 ? 0 : fg);
		tg = (a[i] > 1 ? 0 : tg);
		mx = max(mx, a[i]);
	}
	if(fg == 1)subtask1 :: main();
	else if(tg == 1)subtask2 :: main();
	else subtask3 :: main();
	return 0;
}
/*
0721
*/
