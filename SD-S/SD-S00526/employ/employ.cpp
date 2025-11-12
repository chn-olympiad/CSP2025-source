#include<bits/stdc++.h>
#define int long long
const int N = 505;
const int mod = 998244353;
using namespace std;
int n,m,c[N],p[N],ans,sum[N];
char s[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	bool flag = 1;
	for(int i = 1;i<=n;i++){
		cin >> s[i];
		if(s[i]=='0')flag = 0;
	}
	for(int i = 1;i<=n;i++)cin >> c[i];
	if(n<=10){
		for(int i = 1;i<=n;i++)p[i] = i;
		do{
			int cnt = 0;
			for(int i = 1;i<=n;i++){
				if(cnt>=c[p[i]]){
					cnt++;
					continue;
				}
				if(s[i]=='0')cnt++;
			}
			if(n-cnt>=m)ans ++;
		}while(next_permutation(p+1,p+n+1));
		cout << ans;
	}else if(m==1){
		int cnt = 0;
		ans = 1;
		for(int i = 1;i<=n;i++){
			if(s[i]=='1'){
				cnt++;
				for(int j = 1;j<=n;j++){
					if(c[j]<i)sum[cnt]++;
				}
			}
		}
		for(int i = 1;i<=cnt;i++){
			ans = ans*(sum[i]-i+1)%mod;
		}
		int fac = 1;
		for(int i = 1;i<=n;i++){
			fac = fac*i%mod;
			if(i==n-cnt)ans = (ans*fac)%mod;
		}
		cout << (fac-ans+mod)%mod;
	}else if(m==n){
		int fac = 1;
		for(int i = 1;i<=n;i++){
			if(s[i]=='0'){
				cout << 0;
				return 0; 
			}
			if(c[i]==0){
				cout << 0;
				return 0;
			}
			fac = (fac*i)%mod;
		}
		cout << fac;
	}else{
		int fac = 1;
		for(int i = 1;i<=n;i++)fac = (fac*i)%mod;
		cout << fac;
	}
}
/*
16:43 [24,24]

100+[32,48]+[0,25]+24 = [156,197]
不要挂分不要挂分不要挂分

North London Forever
Whatever the weather
These streets are our own
And my heart will leave you never
My blood will forever
Run through the stone~
COYG!

连着三次省二了，能不能来一次省一
阿森纳三连亚了，能不能来一次冠军
事不过三

去年NOIP太可惜了
因为多写一个=痛失25pts，最后离省一差4pts
能让我赢一次吗,退役之前

RP++
*/
