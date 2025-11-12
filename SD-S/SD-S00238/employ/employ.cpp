#include<bits/stdc++.h>
#define N 998244353
using namespace std;
long long m,n,dy[600],ans,ans1,ans2=0,gv,pd[600];
string s;
void dfs(int d,int p) {
	if(p>m)return;
	if(ans2==n) {
		ans1=1;
		for(int i=1; i<=m-p; i++)ans1=ans1*i%N;
		ans=(ans+ans1)%N;
		return;
	}
	for(int i=1; i<=m; i++) {
		if(pd[i]!=0)continue;
		if(gv>=dy[i]) {
			gv++;
			pd[i]++;
			dfs(d,p+1);
			pd[i]--;
			gv--;
			continue;
		}
		pd[i]++;
		if(s[d]=='1')ans2++;
		else gv++;
		dfs(d+1,p+1);
		pd[i]--;
		if(s[d]=='1')ans2--;
		else gv--;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>m>>n>>s;
	s='0'+s;
	for(int i=1; i<=m; i++) {
		cin>>dy[i];
	}
	dfs(1,0);
	cout<<ans%N;
	return 0;
}


