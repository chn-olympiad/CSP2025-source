#include<iostream>
#include<string>
using namespace std;
const int N=2e5+10;
string s1[N],s2[N];
int n,q;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int l1=t1.size(),l2=t2.size();
		if(l1!=l2)
		{
			printf("0\n");
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int a=t1.find(s1[i]),b=t2.find(s2[i]);
			while(a!=string::npos&&b!=string::npos&&a!=b&&a<l1&&b<l2)
				a=t1.find(s1[i],b),b=t2.find(s2[i],a);
			if(a==string::npos||b==string::npos)
				continue;
			bool flag=1;
			for(int j=0;j<a&&flag;j++)
				if(t1[j]!=t2[j])
					flag=0;
			for(int j=a+s1[i].size();j<l1&&flag;j++)
				if(t1[j]!=t2[j])
					flag=0;
			if(flag)
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
freopen(".in","w",stdin);
freopen(".out","r",stdout);
feropen(".in","r",stdin);
feropen(".out","w",stdout);
I'm luogu uid748678.
Maybe it's my last year in CSP/NOIP.
Hope everything goes best.
*/
