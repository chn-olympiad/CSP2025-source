#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int arr[N],xb=0;
bool pd=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int a=0;a<s.size();a++)
	{
		if(s[a]=='9')
		{
			cout<<9;
			pd=1;
			continue;
		} 
		if(s[a]>='0'&&s[a]<'9')
		{
			arr[xb++]=(s[a]-'0');
		}
	}
	sort(arr,arr+xb);
	for(int a=xb-1;a>=0;a--)
	{
		if(pd==1)
		{
			cout<<arr[a];
		}
		else if(arr[a]!=0)
		{
			pd=1;
			cout<<arr[a];
		}
	}
	if(pd==0)
	{
		cout<<0;
	}
	
	return 0;
} 
