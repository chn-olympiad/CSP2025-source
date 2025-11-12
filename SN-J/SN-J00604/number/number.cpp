//杨俊楠 SN-J00604 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	short int a[1000010];
	cin>>s;
	int ar=1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>=48&&s[i]<=57) 
		{
			a[ar]=(s[i]-48);
			ar++;
		}
	}
	sort(a+1,a+ar);
	for(int i=ar-1;i>0;i--)
		cout<<a[i];
	return 0;
}
