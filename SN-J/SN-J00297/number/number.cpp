//姓名：常智博
//考号：SN-J00297
//学校：西安市高新第一学校 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			cout<<s[i];
			break;
		}
	}
}
