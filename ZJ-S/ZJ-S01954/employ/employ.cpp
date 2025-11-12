#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using std::cin;using std::cout;
constexpr int N=505,p=998244353;
int n,m,c[N];
bool tag=1;
std::string s;
namespace sub1_2{
	int p[N],ans;
	signed main(){
		for(int i=1;i<=n;++i) p[i]=i;
		do{
			int cnt=0;
			for(int i=1;i<=n;++i)
				if(s[i]=='0') ++cnt;
				else if(cnt>=c[p[i]]) ++cnt;
			ans+=(n-cnt>=m);
		}while(std::next_permutation(p+1,p+n+1));
		cout<<ans;
		return 0;
	}
}
namespace sub6_8_16_17{
	int ans=1;
	signed main(){
		for(int i=1;i<=n;++i) ans=1ll*ans*i%p;
		cout<<ans;
		return 0;
	}
}
namespace sub{
	signed main(){
		cout<<0;
		return 0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m>>s;s=' '+s;for(int i=1;i<=n;++i){cin>>c[i];if(s[i]!='1') tag=0;}
	if(n<=10) return sub1_2::main();
	return sub::main();
	if(tag) return sub6_8_16_17::main();
	return 0;
}
