#include<bits/stdc++.h>
#define min(a,b) ((a)>(b)?(a):(b))
#define max(a,b) ((a)<(b)?(a):(b))
#define x first
#define y second

#define endl putchar('\n')
#define air putchar(' ')
using namespace std;
inline int read()
{
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')y=-y;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
	return x*y;
}
const int N= 2e5+10;
int n,m;
pair<string,string> x[N];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		cin>>x[i].x>>x[i].y;
	}
	while(m--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		map<pair<string,pair<string ,int> >,bool>mp;
		for(int i=1;i<=n;i++)
		{
			int op=t1.find(x[i].x);
			if(op!=-1)
			{
				string a=t1.substr(0,op);
				string b=t1.substr(op,x[i].x.size());
				string c=t1.substr(x[i].x.size()+op);
				//cout<<a<<' '<<b<<' '<<c<<'\n';
				if(a+x[i].y+c==t2&&mp[{a,{c,i}}]==0) ans++;
				mp[{a,{c,i}}]=1;
			}
		}
		cout<<ans;endl;
	}
	return 0;
}
