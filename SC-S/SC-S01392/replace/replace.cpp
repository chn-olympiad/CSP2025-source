#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e6 + 10;

int n,q,num[N][3];
string s[N][3],t[3];
vector<int> k[N * 2];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s[i][1] >> s[i][2];
		for(int j = 0;j < s[i][1].size();j++)
			if(s[i][1][j] == 'b') num[i][1] = j;
		for(int j = 0;j < s[i][2].size();j++)
			if(s[i][2][j] == 'b') num[i][2] = j;
		k[num[i][1] - num[i][2] + N].push_back(i);
	}
	for(int i = 1;i <= q;i++){
		cin >> t[1] >> t[2];
		if(t[1].size() != t[2].size()){
			puts("0");
			continue;
		}
		int num1 = 0,num2 = 0,ans = 0;
		for(int j = 0;j < t[1].size();j++)
			if(t[1][j] == 'b') num1 = j;
		for(int j = 0;j < t[2].size();j++)
			if(t[2][j] == 'b') num2 = j;
		int numk = num1 - num2 + N;
		for(int x : k[numk]){
			if(num[x][1] <= num1 && num[x][2] <= num2
			&& s[x][1].size() - num[x][1] <= t[1].size() - num1
			&& s[x][2].size() - num[x][2] <= t[2].size() - num2)
				ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}