#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n,q,p1,l,lss,i,j,k,p;
int sbp1[5000005],sbp2[5000005],tbp1,tbp2;
long long ans;
bool f;
char t,t1[5000005],t2[5000005],s[5000005],ts;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	getchar();
	vector<vector<char> > s1(n);
	vector<vector<char> > s2(n);
	for(i=0;i<n;i++)
	{
		ts=0;
		while(1){t=getchar();if(t==' '||t=='\n') break;if(t=='b') sbp1[i]=ts;ts++;s1[i].push_back(t);p1++;}
		ts=0;
		while(1){t=getchar();if(t==' '||t=='\n') break;if(t=='b') sbp2[i]=ts;ts++;s2[i].push_back(t);p1++;}
	}
//	for(i=0;i<n;i++) for(j=0;j<s1[i].size();j++) cout<<s1[i][j];
	while(q--)
	{
		ans=0;
		cin>>t1>>t2;
		l=strlen(t1);
		if(p1<=20000)
		{
			for(i=0;i<l;i++)
			{
				for(j=0;j<n;j++)
				{
					f=0;
					lss=s1[j].size();
					for(k=0;k<lss;k++)
						if(t1[i+k]!=s1[j][k])
						{
							f=1;
							break;
						}
					if(!f)
					{
						strcpy(s,t1);
						for(k=0;k<lss;k++)
							s[i+k]=s2[j][k];
						if(strcmp(s,t2)==0) ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			ans=0;
			for(i=0;i<l;i++)
			{
				if(t1[i]=='b') tbp1=i;
				if(t2[i]=='b') tbp2=i;
			}
			for(i=0;i<n;i++)
			{
				if(tbp2-tbp1==sbp2[i]-sbp1[i]&&sbp1[i]<=tbp1&&s1[i].size()<=l&&s1[i].size()-sbp1[i]<=l-tbp1)
				{
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
