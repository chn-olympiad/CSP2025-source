#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
inline int qread(){
	#define qr qread()
	int x=0,c=getchar(),t=1;
	while(c<'0'||c>'9'){
		t^=(c=='-');
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return (t?x:-x);
}
inline void qwrite(int x){
	#define qw(_) qwrite(_)
	#define qws(_) qw(_),putchar(' ')
	#define qwe(_) qw(_),putchar('\n')
	if(x<0) putchar('-'),x=-x;
	if(x>9) qw(x/10);
	putchar(x%10+'0');
	return;
}
string s[N],t[N];
map<int,int>kmps[N],kmpt[N];
int l[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=qr,T=qr;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		int len=s[i].size();
		l[i]=len;
		s[i]=" "+s[i];
		t[i]=" "+t[i];
		int m=0;
		for(int j=2;j<=len;j++){
			while(m&&s[i][m+1]!=s[i][j]) m=kmps[i][m];
			if(s[i][m+1]==s[i][j]) m++;
			kmps[i][j]=m;
		}
	}
	while(T--){
		string x,y;
		cin>>x>>y;
		int len=x.size();
		x=" "+x;
		y=" "+y;
		int ans=0;
		for(int i=1;i<=n;i++){
			int m=0;
			for(int j=1;j<=len;j++){
				while(m&&s[i][m+1]!=x[j]) m=kmps[i][m];
				if(s[i][m+1]==x[j]) m++;
				if(m==l[i]){
					bool flag=true;
					for(int k=j-l[i]+1;k<=j;k++) if(t[i][k-j+l[i]]!=y[k]){
						flag=false;
						break;
					}
					for(int k=j+1;k<=len;k++) if(x[k]!=y[k]){
						flag=false;
						break;
					}
					for(int k=1;k<=j-l[i];k++) if(x[k]!=y[k]){
						flag=false;
						break;
					}
					if(flag){
						ans++;
						break;
					}
					m=kmps[i][m];
				} 
			}
		}
		qwe(ans);
	}
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
