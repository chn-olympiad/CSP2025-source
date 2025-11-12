#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 7;
const long long mod = 998244353;

long long F(long long x){
	if(x <= 1){
		return 1;
	}
	return (F(x - 1) * x) % mod;
}
bool cmp(int a,int b){
	return a > b;
}


long long n,m;
string s;
int c[MAXN];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	cin >> s;
	bool flag = true;
	int c_0 = 0;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
		if(c[i] == 0){
			c_0++;
		}
	}
	int cnt_1 = 0;
	int app_1 = -1;
	for(int i = 0;i < n;i++){
		if(s[i] != '1'){
			flag = false;
		}else{
			cnt_1++;
			if(app_1 == -1){
				app_1 = i;
			}
		}
	}
	if(m == 1){
		sort(c + 1,c + n + 1,cmp);
		int now = 1;
		long long ans = 0;
		while(c[now] > app_1){
			ans++;
			now += 1;
		}
		ans = (ans * F(n - 1)) % mod;
		printf("%lld\n",ans);
	}else if(cnt_1 < m or cnt_1 < n - c_0){
		printf("0");
	}else if(flag){
		printf("%lld\n",F(n - c_0));
	}
	return 0;
}
