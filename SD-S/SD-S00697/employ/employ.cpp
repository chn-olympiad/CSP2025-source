// (1~2) = 8pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x;
	scanf("%lld",&x);
	return x;
}
const int N=510,MOD=998244353;
int c[N];
char s[N];
bool check_all1(int n){
	for(int i=1;i<=n;++i)
		if(s[i]=='0')
			return false;
	return true;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
		c[i]=read();
	if(n>=15){
		printf("0\n");
		return 0;
	}
	vector<int>_per;
	for(int i=1;i<=n;++i)
		_per.push_back(i);
	int tot=0;
	do{
		int mg=0,j=0,cnt=0;
		for(auto i:_per){
			++j;
			if(mg>=c[i])
				++mg;
			else if(s[j]=='1')
				++cnt;
			else ++mg;
		}
		if(cnt>=m)
			++tot;
	}
	while(next_permutation(_per.begin(),_per.end()));
	printf("%lld\n",tot%MOD);
	return 0;
}
/*

Input #1:

3 2
101
1 1 2

Output #1:

2

Input #2:

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

Output #2:

2204128

*/ 
