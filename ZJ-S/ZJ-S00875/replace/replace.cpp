#include<bits/stdc++.h>
using namespace std;
int n,q,l[10001],is,ans;
string a[10001],b[10001];
string c,d;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		l[i]=a[i].length();
	}
	for(int i=1;i<=q;i++)
	{
		cin>>c>>d;
		ans=0;
		for(int j=0;j<c.length();j++)
		{
			for(int f=1;f<=n;f++)
			{
				is=1;
				if(c.length()-j<l[f]) continue;
				for(int ff=0;ff<l[f];ff++)
				{
					if(c[j+ff]!=a[f][ff])
					{
						is=0;
						break;
					}
				}
				if(!is) continue;
				for(int ff=0;ff<j;ff++)
				{
					if(c[ff]!=d[ff])
					{
						is=0;
						break;
					}
				}
				if(!is) continue;
				for(int ff=j;ff<j+l[f];ff++)
				{
					if(b[f][ff-j]!=d[ff])
					{
						is=0;
						break;
					}
				}
				if(!is) continue;
				for(int ff=j+l[f];ff<c.length();ff++)
				{
					if(c[ff]!=d[ff])
					{
						is=0;
						break;
					}
				}
				if(!is) continue;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
	fclose(stdin);fclose(stdout);
}
