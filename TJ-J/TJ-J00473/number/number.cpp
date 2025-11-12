#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int www=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int qqq=s[i]-48;
			//cout<<s[i]<<" "<<qqq<<endl;
			a[www]=qqq;
			www++;
		}
	}
	sort(a+1,a+www+1);
	for(int i=www;i>1;i--)
	{
		cout<<a[i];
	}
	//cout<<endl<<www;
	return 0;
}
