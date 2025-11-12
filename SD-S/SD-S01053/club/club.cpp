#include<bits/stdc++.h>

#define pii pair<int,int>

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

int n;
int a[100005][5];
int dp[205][205][205];

struct nd{
	int x,y,z;
}b[100005];

bool cmp(nd l,nd r){
	bool wl = ((l.x > 0)||(l.y > 0));
	bool wr = ((r.x > 0)||(r.y > 0));
	if(wl != wr) return wl > wr;
	return l.x-max(0,l.y) > r.x-max(0,r.y);
}

void qy(){
	
	n = read();
	for(int i = 1;i <= n;++ i)
		for(int j = 1;j <= 3;++ j)
			a[i][j] = read();
	
	{//ÌØÊâÐÔÖÊ
	if(n <= 200){
		for(int i = 0;i < n;++ i){
			for(int j = 0;j <= i;++ j){
				for(int k = 0;j+k <= i;++ k){
					dp[i+1][j+1][k] = max(dp[i+1][j+1][k]
					,dp[i][j][k]+a[i+1][1]);
					dp[i+1][j][k+1] = max(dp[i+1][j][k+1]
					,dp[i][j][k]+a[i+1][2]);
					dp[i+1][j][k] = max(dp[i+1][j][k]
					,dp[i][j][k]+a[i+1][3]);
				}
			} 
		}
		int ans = 0;
		for(int j = 0;j <= n/2;++ j){
			for(int k = n/2-j;k <= n/2;++ k){
				ans = max(ans,dp[n][j][k]);
			}
		}
		print(ans);
		printf("\n");
		for(int i = 1;i <= n;++ i)
			for(int j = 0;j <= n;++ j)
				for(int k = 0;k <= n;++ k)
					dp[i][j][k] = 0;
		return;
	}
	
	bool xza = 1,xzb = 1;
	
	for(int i = 1;i <= n;++ i){
		if(!(a[i][2] == 0&&a[i][3] == 0)) xza = 0;
		if(!(a[i][3] == 0)) xzb = 0;
	}
	
	if(xza){
		vector<int> v;
		for(int i = 1;i <= n;++ i) v.push_back(a[i][1]);
		sort(v.begin(),v.end());
		int ans = 0;
		for(int i = 1;i <= n/2;++ i)
			ans += v[n-i];
		print(ans);
		printf("\n");
		return;
	}
	
	if(xzb){
		for(int i = 1;i <= n;++ i) b[i] = {a[i][1],a[i][2]};
		sort(b+1,b+1+n,cmp);
		int ans = 0;
		for(int i = 1;i <= n/2;++ i)
			ans += b[i].x;
		for(int i = n/2+1;i <= n;++ i)
			ans += b[i].y;
		print(ans);
		printf("\n");
		return; 
	}
	}
	
	for(int i = 1;i <= n;++ i) b[i] = {a[i][1],a[i][2],a[i][3]};
	
	int ans = 0,sum = 0;
	for(int i = 1;i <= n;++ i)
		sum += b[i].z,b[i].x -= b[i].z,b[i].y -= b[i].z;
	
	sort(b+1,b+1+n,cmp);
	
	int sum1 = 0,sum2 = 0;
	for(int i = 0;i < n/2;++ i) sum2 += b[i].y;
	int mx = sum2+b[n/2].y-b[0].y;
	for(int i = 0;i <= n/2;++ i){
		sum1 += b[i].x;
		int l = n/2,r = n/2+i;
		mx -= b[i].y;
		sum2 -= b[i].y;
		sum2 += b[r].y;
		mx = max(mx,sum2);
		ans = max(ans,sum1+mx+sum);
	}
	
	print(ans);
	printf("\n");
	return; 
	
}

signed main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int _;
	cin >> _;
	while(_--) qy();
	
	return 0;
	
} 
