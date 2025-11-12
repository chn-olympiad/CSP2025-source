#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!(c>='0'&&c<='9')){if(c=='-') f=-1;c=getchar();}
	while((c>='0'&&c<='9')){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read(),m=read(),cc=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]=='0') cc=1;
	}
	if(cc==0){
		int res=1;
		for(int i=1;i<=n;++i){
			res*=i;
			res%=998244353;
		}
		cout<<res;
		return 0;
	}
}
