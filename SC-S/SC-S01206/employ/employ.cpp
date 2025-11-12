#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int s[N];
int a,b;
int c[N];

int ans = 0;

int n,m;

int dfs(string x,int aa,int bb) {
	int now = x.size();
	if(now >= n) {
		ans++;
		return 0;
	}
	if(aa > 0) {
		dfs(x+'0',aa-1,bb);
	}else if(bb > 0 && c[now+1]-1 > now - aa) {
		dfs(x+'1',aa,bb-1);
	}
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
//	cin>>n>>m;
//	for(int i =1;i <= n;i++) {
//		cin>>s[i];
//	}
//	for(int i =1;i <= n;i++) {
//		cin>>c[i];
//	}
	cout<<0;
	return 0;
}