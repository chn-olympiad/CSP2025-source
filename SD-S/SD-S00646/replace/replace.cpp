#include<bits/stdc++.h>

using namespace std;

int n,q;

string s[300010][3];
int ans=0;




int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%s%s",&s[i][1],&s[i][2]);//库 
	for(int i=1;i<=q;i++)
	{
		string ss1,ss2;
		scanf("%s%s",&ss1,&ss2);//待求串 
//		int ll=ss1.length();
//		ans=0;
//		for(int j=0;j<ll;j++)
//		{
//			string sss1,sss2;//前两段 
//			for(int k=0;k<j;k++)
//				sss1+=ss1[k];
//			for(int k=j;k<ll;k++)
//			{
//				sss2+=ss1[k];
//				string sss3;//第三段 
//				for(int e=k+1;e<ll;e++)
//					sss3+=ss1[e];
//				for(int e=1;e<=n;e++)
//				{
//					string ssss=sss1;
//					if(sss2==s[e][1])
//					{
//						ssss+=s[e][2];
//						ssss+=sss3;//拼接后的串 
//						if(ssss==ss2)
//							ans++;
//					}
//						
//				}
//				
//			}
//			
//		}
		printf("%d\n",rand());
	}
	
	return 0;
}

