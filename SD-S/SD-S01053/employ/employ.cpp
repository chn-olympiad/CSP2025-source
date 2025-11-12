#include<bits/stdc++.h>

#define int long long
#define mod 998244353

using namespace std;

int read(){
	int x = 0,y = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9'){
		if(ch == '-') y = -1;
		ch = getchar();
	}
	while(ch >= '0'&&ch <= '9'){
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x*y;
}

void print(int x){
	char ch = x%10+'0';
	if(x < 10){
		printf("%c",ch);
		return;
	}
	print(x/10);
	printf("%c",ch);
}

int n,m;
char s[505];
int c[505];
int p[505];
bool vs[505];
int ans;

void dfs(int x,int qsum){
	if(x > n){
		if(qsum+m <= n) ans++;
		return;
	}
	if(qsum+m > n) return;
	for(int i = 1;i <= n;++ i){
		if(!vs[i]){
			vs[i] = 1;
			p[x] = i;
			int t = qsum;
			if(qsum >= c[i]||s[x] == '0') qsum++;
			dfs(x+1,qsum);
			qsum = t;
			vs[i] = 0;
		}
	}
}

signed main(){

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	n = read();m = read();
	int gs = 0;
	for(int i = 1;i <= n;++ i){
		cin >> s[i];
		if(s[i] == '1') gs++;
	}
	for(int i = 1;i <= n;++ i)
		cin >> c[i]; 
	
	if(gs < m){
		print(0);
		return 0;
	}
	
	if(n >= 100&&m == 1){
		if(s[1] == '1'){
			int ans = 1;
			for(int i = 2;i <= n;++ i)
				ans *= i,ans %= mod;
			print(ans);
			return 0;
		}
	}
		
	dfs(1,0);
	print(ans);
	return 0;

	return 0;

}

