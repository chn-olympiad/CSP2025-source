#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,q,ans;
string s1[N],s2[N],s,str1,str2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--)
	{
		cin>>str1>>str2;
		int len1=str1.size(),len2=str2.size();
		ans=0;
		for(int i=1;i<=len1;i++)
		{
			for(int l=0;l+i-1<len1;l++)
			{
				int r=l+i-1;
				s=str1[l];
				for(int j=l+1;j<=r;j++)
					s+=str1[j];
				for(int j=1;j<=n;j++)
				{
					if(s==s1[j])
					{
						s=s2[j];
						string x=str1;
						for(int k=l,js=0;k<=r;k++,js++)
						{
							x[k]=s[js];
						}
						if(x==str2)
							ans++;
						break;
					}
				}
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
