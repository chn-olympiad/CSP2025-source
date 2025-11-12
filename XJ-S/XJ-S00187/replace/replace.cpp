#include<bits/stdc++.h>
using namespace std;
string c[200005],c1[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,i,sum;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>c[i]>>c1[i];
	}
	while(q--)
	{
		string a,b,t="",t1="";sum=0;
		int len=-1;
		cin>>a>>b;
		while(1)
		{
			len++;
			if(a[len]<'a'||a[len]>'z')
			{
				break;
			}
		}
		for(i=0;i<=len;i++)
		{
			if(a[i]!=b[i])
			{
				t+=a[i];
				t1+=b[i];
			}
		}
		for(i=1;i<=n;i++)
		{
			if(c[i]==a&&c1[i]==b) sum++;
			else
			{
				if(t==c[i]&&t1==c1[i]) sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
