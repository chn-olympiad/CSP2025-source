#include<bits/stdc++.h>
using namespace std;
int main(){
//  freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	string s;
	int a[100000];
	cin>>s;
	int p=s.length();
	int y=0;
	for(int d=0;d<p;d++)
	{
		if(s[d]<='9' && s[d]>='0')
		{
			a[d]=s[d]-'0';
			y++;
		}
	}
	for(int i=0;i<p;i++)
	{
		for(int j=1;j<p;j++)
		{
			if(a[j]>a[j-1])
			{
				swap(a[j],a[j-1]);
			}
		}
	}
	for(int i=0;i<y;i++)
	{
		cout<<a[i];
	}
	return 0;
}