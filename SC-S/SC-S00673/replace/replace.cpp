#include<bits/stdc++.h>
using namespace std;

const int M=2e5+10;
int n,q;
map<string,int> ma;
string to[M];
string pr[M],re[M];
string t1,t2;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	char s1[M],s2[M];
	for(int i=1;i<=n;i++)
	{
		scanf("%s %s",s1,s2);
		string st1="",st2="";
		for(int i=0;i<(int)strlen(s1);i++)
			st1=st1+s1[i],st2=st2+s2[i];
		ma[st1]=i;
		to[i]=st2;
	}
	
	while(q--)
	{
		scanf("%s %s",s1+1,s2+1);
		t1=t2="";
		for(int i=1;i<=(int)strlen(s2);i++)
			t2=t2+s2[i];
		pr[0]="";
		for(int i=1;i<=(int)strlen(s1);i++)
			pr[i]=pr[i-1]+s1[i];
		re[(int)strlen(s1)+1]="";
		for(int i=strlen(s1);i>=1;i--)
			re[i]=s1[i]+re[i+1];
		int ans=0;
		for(int l=1;l<=(int)strlen(s1);l++)
		{
			string mid="";
			for(int r=l;r<=(int)strlen(s1);r++)
			{
				mid=mid+s1[r];
				string tp=pr[l-1]+mid+re[r+1];
				if(ma[mid]>=1&&ma[mid]<=n)
				{
					t1=pr[l-1]+to[ma[mid]]+re[r+1];
					if(t1==t2) ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}