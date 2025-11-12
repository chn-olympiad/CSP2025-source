#include <bits/stdc++.h>
#define int long long
int n,m;
std::string s;
int c[105];
int p[105];
int check(){
	int resigncnt=0;
	for(int i=1;i<=n;i++){
		//std::cout<<s[i]<<' ';
		if(s[i]=='0')resigncnt++;
		else if(c[p[i]]<=resigncnt)resigncnt++;
	}//std::cout<<resigncnt<<'\n';
	return resigncnt<=(n-m);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	std::ios::sync_with_stdio(0);
//	std::cin.tie(0);
	std::cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		std::cin>>c[i];
	}
	for(int i=1;i<=n;i++)p[i]=i;
	int tot=0;
	do{
		tot+=check();
	}while(std::next_permutation(p+1,p+n+1));std::cout<<tot<<'\n';
	return 0;
}
//csps rp++!
//scanf 用lld!
//算算空间时间!
//Ren5Jie4Di4Ling5%
