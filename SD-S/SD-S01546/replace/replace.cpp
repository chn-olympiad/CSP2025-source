#include<iostream>
using namespace std;
int n,q,Next[1005][2005];
string s1[200005],s2[200005];
long long ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		int j=0;
		for(int k=1;k<=s1[i].length();k++)
		{
			while(s1[i][k]!=s1[i][j]&&j){j=Next[i][j];}
			if(s1[i][k]==s1[i][j]){j++;}
			Next[i][k+1]=j;
		}
	}
	while(q--)
	{
		string a,b;
		cin>>a>>b;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a.length()<s1[i].length()){continue;} 
			if(a.length()==s1[i].length())
			{
				if(a==s1[i]&&b==s2[i]){ans++;}
				continue;
			}
			int j=0;
			for(int k=1;k<=a.length();k++)
			{
				while(a[k]!=s1[i][j]&&j){j=Next[i][j];}
				if(a[k]==s1[i][j]){j++;}
				if(j==s1[i].length())
				{
					string c="";
					for(int wow=0;wow<j;wow++){c+=a[wow];}
					for(int wow=0;wow<s1[i].length();wow++){c+=s2[i][wow];} 
					for(int wow=s1[i].length()+j;wow<a.length();wow++){c+=a[wow];}
					if(b==c){ans++;}
				}
			}
		}
		cout<<ans<<"\n"; 
	}
	return 0;
}
