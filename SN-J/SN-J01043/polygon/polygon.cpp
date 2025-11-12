#include<bits/stdc++.h>
using namespace std;

int n,nowmax = -1;
int a[5005];
int dp[5005][5005];
int maxn[5005];
int qianzhui[5005];

int getsum(int x, int y){
	return qianzhui[y] - qianzhui[x-1];
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;++i){
		qianzhui[i] = qianzhui[i-1] + a[i];
		maxn[i] = max(maxn[i-1],a[i]);
	}
	
	if(n == 3){
		cout << (qianzhui[3] > (2 * maxn[3])) ? 1 : 0;
		return 0;
	}
	cout << 0;
	return 0;
}
