#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;
#define int long long
#define R(x) x=read()
#define W(X) write(x)
#define MAXN 100010
inline int read()
{
	int x,y;
	x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') y=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
	return x*y;
}
inline void write(int x)
{
	if(x<0) {putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
unordered_map<string,int> mp;
string s[MAXN],t[MAXN];
int n,q;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	R(n);R(q);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>t[i];
		mp[s[i]]=i;
	}
	int ans=0;
	for(int i=1;i<=q;i++)
	{
		string c1,c2;
		cin>>c1>>c2;
		int l=c1.size();
		for(int j=0;j<l;j++)
			for(int k=j+1;k<l;k++)
			{
				string nw=c1.substr(j,k-j+1);
				string cp=c1;
				if(mp[nw])
				{
					int id=mp[nw];
					for(int x=j;x<=k;x++)
						cp[x]=t[id][x-j];
					if(cp==c2) ans++;
//					cout<<j<<' '<<k<<' '<<cp<<endl;
				}
			}
		cout<<ans<<endl;
		ans=0;
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

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
