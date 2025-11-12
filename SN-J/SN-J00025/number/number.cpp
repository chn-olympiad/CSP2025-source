//SN-J00025 付黄旗正 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int a[1000004],cot=1;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s[i]!=0;i++)
	{
		if(s[i]>91)
		{
			continue;
		}
		else if(s[i]>=47&&s[i]<=58)
		{
			a[cot]=s[i]-48;
			cot++;
		}
	}
	sort(a,a+cot+1);
	for(int i=cot;i>1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
