#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6+5;
int n,q,ans=0;
string s1[N],s2[N];
string t1[N],t2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1[i]>>t2[i];
		int l1=t1[i].size(),l2=t2[i].size()+1;
		t1[i]=' '+t1[i]+' ';
		ans=0;
		string s_1="",s_2="",str;
		for(int o=0;o<=l1;o++)
		{
			if(o!=0)	s_1+=t1[i][o];
			s_2="";
			for(int j=l2;j>o;j--)
			{
				if(j!=l2)	s_2=t1[i][j]+s_2;
				
				for(int p=o+1;p<j;p++)
				{
					str+=t1[i][p];
				}
				for(int l=1;l<=n;l++)
				{
					
					if(str==s1[l])
					{
						if(s_1+s2[l]+s_2==t2[i])
							ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
