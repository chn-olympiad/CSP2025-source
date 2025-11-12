#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define ll long long
#define sf std :: flush
#define lowbit(x) (x & (-x))
#define endl '\n'
const int N = 505;
const ll mod = 998244353;
int c[N],p[N],n,m;
string s;
bool check(){
	int cnt = 0,cnt2 = 0;
	for(int i = 1;i <= n;i++){
		if(s[i] == '0') cnt2++;
		else{
			int C = c[p[i]];
			if(cnt2 >= C) cnt2++;
			else cnt++;
		}
		if(cnt >= m) return true;
	}
	return false;
}
int main(){
	ios :: sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int ans = 0; cin >> n >> m;
	cin >> s;
	s = '?' + s;
	for(int i = 1;i <= n;i++) cin >> c[i],p[i] = i;
	do{
		ans += check(); 
	}while(next_permutation(p+1,p+1+n));
	cout<<ans<<endl;
	cout<<sf;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


