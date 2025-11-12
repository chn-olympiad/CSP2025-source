#include<bits/stdc++.h>
using namespace std;
inline string reads()
{
	string s="";
	char c=getchar();
	while(c<'a'||'z'<c) c=getchar();
	while('a'<=c&&c<='z'){
		s=s+c;
		c=getchar();
	}
	return s;
}
inline void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,q,ans;
string u,v;
pair<string,string> len[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		len[i].first=" "+reads();
		len[i].second=" "+reads();
	}
	sort(len+1,len+n+1);
//	for(int i=1;i<=n;i++) cout<<len[i].first<<" ";
//	cout<<1;
	for(int i=1;i<=q;i++)
	{
//		cout<<1;
		u=" "+reads();
		v=" "+reads();
		ans=0;
		for(int j=1;j<u.size();j++)
		{
			if(u[j-1]!=v[j-1]) break;
//			cout<<1;
			int l=1,r=n,mid,st=0;
			while(l<=r)
			{
				mid=(r-l)/2+l;
				if(len[mid].first[1]>=u[j]) r=mid-1,st=mid;
				else l=mid+1;
			}
			if(len[st].first[1]!=u[j]) continue;
			if(!st) continue;
			while(len[st].first[1]==u[j])
			{
				string str=len[st].first,ch=len[st].second;
				bool f=0;
				for(int k=1;k<str.size();k++)
				{
					if(str[k]!=u[j+k-1]){f=1;break;}
				}
				if(!f)
				{
					string t=u;
					for(int k=1;k<ch.size();k++)
					{
						if(ch[k]!=v[j+k-1]){f=1;break;}
					}
					for(int k=j+ch.size()-1;k<u.size();k++)
					{
						if(u[k]!=v[k]){f=1;break;}
					}
					if(!f) ans++;
				}
				st++;
			}
		}
		write(ans),putchar('\n');
	}
	return 0;
}
