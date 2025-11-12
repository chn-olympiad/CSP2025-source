#include<bits/stdc++.h>
using namespace std;
int n,q,x,y,le,summ;
char g;
bool z;
int l[5000006],s1[5000006],s2[5000006];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;getchar();
	for(int i=1;i<=n;++i)
	{
		g=getchar();
		while(g!=' ')
		{
			l[i]++;
			if(g=='b')z=true;
			if(!z)s1[i]++;
			g=getchar();
		}
		getchar();z=false;
		while(g!='\n')
		{
			if(g=='b')z=true;
			if(!z)s2[i]++;
			g=getchar();
		}
		z=false;
	}
	for(int i=1;i<=q;++i)
	{
		g=getchar();
		while(g!=' ')
		{
			le++;
			if(g=='b')z=true;
			if(!z)x++;
			g=getchar();
		}
		getchar();z=false;
		while(g!='\n')
		{
			if(g=='b')z=true;
			if(!z)y++;
			g=getchar();
		}
//		cout<<x<<" "<<y<<" "<<le<<endl;
		if(x!=y)printf("0\n");
		else 
		{
			for(int i=1;i<=n;++i)
			{
//				cout<<l[i]<<" "<<s1[i]<<" "<<s2[i]<<endl;
			if(x>=s1[i]&&x>=s2[i]&&le-x>=l[i]-s1[i]&&le-x>=l[i]-s2[i])
			summ++;
			}
			cout<<summ<<endl;
			summ=0;
			
		}
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
