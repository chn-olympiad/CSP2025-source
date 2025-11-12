//8pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string s;
int a[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(n<=10){
		int f[11]={0,0,0,0,0,0,0,0,0,0,0};
		for(int i=1;i<=n;++i)f[i]=i;
		int fail=0,cnt=0,ans=0;
		do{
			fail=cnt=0;
			for(int i=1;i<=n;++i){
				if(fail>=a[f[i]]){
					++fail;
					continue;
				}
				if(s[i-1]=='1')++cnt;
				else ++fail;
			}
			ans+=(cnt>=m);
		}while(next_permutation(f+1,f+n+1));
		cout<<ans;
	}
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
