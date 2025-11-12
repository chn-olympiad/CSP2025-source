#include<bits/stdc++.h>
using namespace std;

int n,q;
const int N = 2e5 + 10;
string s1,s2,t1,t2;
int a[N],b[N],dp[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s1 >> s2;
		int x = s1.size();
		for(int j = 0;j < x;j++){
			if(s1[j] == 'b') a[i] = j;
			if(s2[j] == 'b') b[i] = j;
		}
	}
	while(q--){
		memset(dp,0,sizeof dp);
		cin >> t1 >> t2;
		int bt1 = 0,bt2 = 0,x = t1.size();
		for(int i = 0;i < x;i++){
			if(t1[i] == 'b') bt1 = i;
			if(t2[i] == 'b') bt2 = i;
		}
		dp[bt1] = 1;
		for(int i = 1;i <= n;i++){
			dp[b[i]] += dp[a[i]];
		}
		cout << dp[bt2] << endl;
	}
	return 0;
}