#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 505;
int n,m,p[N];
int c[N];
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	cin >> (s + 1);
	for(int i = 1;i <= n;++ i) cin >> c[i],p[i] = i;
	int ans = 0;
	do{
		int cnt = 0;
		int sum = 0;
		for(int i = 1;i <= n;++ i){
			if(sum >= c[p[i]]){
				++ sum;
				continue;
			}
			if(s[i] == '0') ++ sum;
		}
		if(n - sum >= m) ++ ans;
	}while(next_permutation(p + 1,p + 1 + n));
	cout << ans;
	return 0;
}
/*
3 2
101
1 1 2

*/