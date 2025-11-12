#include <bits/stdc++.h>
#define f(i,a,b,c) for(int i=a;i<=b;i+=c)
#define F(i,a,b,c) for(int i=a;i>=b;i-=c)
using namespace std;
const int N=2e5+1;
int n,q,ans;
string s[N][2],t1,t2,s1,s2;
int read(){
	int X=0,F=1;
	char C=getchar();
	while(C<'0'||C>'9'){if(C=='-') F=-1;C=getchar();}
	while(C>='0'&&C<='9'){X=X*10+C-'0';C=getchar();}
	return X*F;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	if(n<=100&&q<=100){
		f(i,1,n,1) cin>>s[i][0]>>s[i][1];
		while(q--){
			cin>>t1>>t2;
			if(t1.size()!=t2.size()){puts("0");continue;}
			int l=t1.size();
			f(i,0,l-1,1) f(j,i,l-1,1){
				s1=t1.substr(0,i);
				s2=t2.substr(0,i);
				if(s1!=s2) continue;
				s1=t1.substr(j+1,l-j+1);
				s2=t2.substr(j+1,l-j+1);
				if(s1!=s2) continue;
				s1=t1.substr(i,j-i+1);
				s2=t2.substr(i,j-i+1);
				f(k,1,n,1) if(s[k][0]==s1&&s[k][1]==s2) ans++;
			}
			printf("%d\n",ans);
		}
	}
	else f(i,1,q,1){ puts("0");}
	return 0;
}
