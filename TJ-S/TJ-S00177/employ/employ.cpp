#include<bits/stdc++.h> 
using namespace std;
int n,m;
long long c,res;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> s;
	cin >> c;
	for(int i=1;i<=n;i++){
		c *=m;
		c%=998244353;
	}
	res = c;
	for(int i=1;i<=n;i++){
		cin >> c;
	}
	cout << res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
