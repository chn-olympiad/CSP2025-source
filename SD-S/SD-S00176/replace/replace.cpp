#include <bits/stdc++.h>
using namespace std;
char t3[1005][1005],t4[1005][1005],t5[1005][1005],t6[1005][1005];
string s1[100005],s2[100005];
string t1[100005],t2[100005];
long long cnt;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	long long ans=0;
	for (int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	
	for (int i=1;i<=q;i++)cin>>t1[i]>>t2[i];
	for (int i=1;i<=q;i++)
	{
		cnt=-1;
		for (int j=0;j<=t1[i].length();j++)
		{

			if(t1[i][j]!=t2[i][j])
			{
				
				t3[i][++cnt]=t1[i][j];
				t4[i][cnt]=t2[i][j];
			}
			
			
		}
		
	}
	for (int i=1;i<=n;i++)
	{
		cnt=-1;
		for (int j=0;j<=s1[i].length();j++)
		{
			
			if(s1[i][j]!=s2[i][j])
			{
				
				t5[i][++cnt]=s1[i][j];
				t6[i][cnt]=s2[i][j];
			}
			
			
		}
		
	}
	for (int i=1;i<=q;i++)
	{
		ans=0;
		for (int j=1;j<=n;j++)
		{
			bool check=1;
			if (strcmp(t3[i],t5[j])==0||strcmp(t4[i],t6[j])==0)
			{
			ans++;}
		}
		cout<<ans<<endl;
	}
	//10pts
} 
