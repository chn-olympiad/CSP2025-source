#include<bits/stdc++.h>
using namespace std;
int main()
{
	//SN-J00695焦一峥 白水县城关镇第一初级中学 
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	string s;
	int n;
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]=='0' || s[i]<='9')
		{
			while(s.size())
			{
				if(s[i]>s[i+1])
				{
					cout<<s[i];
				}
				break;
			}
		}
		
	}
	return 0;
}
