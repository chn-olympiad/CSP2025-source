#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, k;
int a[N];
int x[N];
int dp[N];
int maxdp[N];
int L(int b){//(+1)
	int cnt=0;
	while(b>0){
		cnt++;
		b>>=1;
	}
	return cnt;
}
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	//bool allone = 1;
	bool allonezero = 1;
	int macnt=0;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		//if(a[i] != 1) allone = 0;
		if(a[i] != 1 && a[i] != 0) allonezero = 0; 
		x[i] = x[i - 1] ^ a[i];
		if(a[i] == k) dp[i] = 1;
		macnt=max(macnt,L(a[i]));
	}
	//cout<<macnt<<'\n';
	if(k>(1<<macnt)-1){
		cout <<0;
		return 0;
	}
	/*if(allone){
		if(k == 0 || k == 1){
			
		}
		else cout << 0;
		return 0;
	}*/
	if(n>1000&&allonezero){
		if(k > 1) cout << 0;
		else{
			if(k == 1){
				int ans = 0;
				for(int i = 1;i <= n;i ++){
					if(a[i] == 1) ans ++;
				}
				cout << ans;
				return 0;
			}
			if(k == 0){
				int ans = 0;
				for(int i = 1;i <= n;i ++){
					if(a[i] == 0) ans ++;
				}
				cout << ans;
			}
		}
		return 0;
	}
	for(int i = 1;i <= n;i ++){
		for(int j = i - 1;j >= 0;j --){
			int o = x[i] ^ x[j];
			if(o == k){
				dp[i]=maxdp[j]+1;
				/*for(int l = 0;l <= j;l ++){
					dp[i] = max(dp[i], dp[l] + 1);
				}*/
				break;
			}
		}
		maxdp[i]=max(maxdp[i-1],dp[i]);
		/*int madp=0;
		for(int j = 0;j < i;j ++){
			//j + 1 ~ i
			int o = x[i] ^ x[j];
			/*int p = 0;
			for(int l = j + 1;l <= i;l ++)
				p ^= a[l];
			if(p!=o){
				cout<<"WA";
				return 0;
			}
			madp=max(madp,dp[j]);
			if(o == k){
				dp[i] = max(dp[i], madp + 1);
			}
		}*/
	}
	int ma = 0;
	for(int i = 1;i <= n;i ++){
		ma = max(ma, dp[i]);
	}
	cout << ma;
	return 0;
}
/*
5 3
1 2 3 4 5
我大明天下无敌啊！！！ 
*/
