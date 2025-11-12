#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,Q,s;
string a[N],b[N],s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;++i)
	  cin>>a[i]>>b[i];
	while(Q--)
	{
		s=0;
		cin>>s1>>s2;
		int len=s1.size(),k1=0,k2=0;
		for(int i=1;i<len;++i)
		{
			if(s1[i]!=s1[i-1]) ++k1;
			if(k1==2)
			{
				k1=i-1;
				break;
			}
		}
		for(int i=1;i<len;++i)
		{
			if(s2[i]!=s2[i-1]) ++k2;
			if(k2==2)
			{
				k2=i-1;
				break;
			}
		}
		for(int i=1;i<=n;++i)
		  if(s1.find(a[i])<len&&s2.find(b[i])<len) ++s;
		printf("%d\n",s);
	}
	return 0;
}
