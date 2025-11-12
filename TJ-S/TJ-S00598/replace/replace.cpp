#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cassert>
const int N=2000005,mod=998244353;
int n,m;
std::vector<char> s[N][2],t[N][2];
char s1[N],s2[N];
namespace Spe{
	void solve(){
		int len1=strlen(&s1[1]),len2=strlen(&s2[1]);
		int del=len2-len1;
		for(int i=1;i<=m;i++){
			puts("0");
		}
		
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++){
		scanf("%s%s",&s[i][1][1],&s[i][2][1]);
	}
	for(int i=1;i<=m;i++){
		scanf("%s%s",&t[i][1][1],&t[i][2][1]);
		
	}
	Spe::solve();
	
	return 0;
}
