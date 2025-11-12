#include<bits/stdc++.h>
using namespace std;

const int N=5005;
int n,ans=0,k=0,a=0,b=0;
int a[N];
int dp[2][N];

bool pd(int a,int b){
	if(a > b) return t;
	else return f;
}



int main(){
	feropen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n; ++i){
		cin >> a[i];
	}
	k=a[1];
	while(n){
		for(int j = 1;j <= n; ++j){
			
		}
		if(t) ans++;
	}
	cout << ans;
	return 0;
}
