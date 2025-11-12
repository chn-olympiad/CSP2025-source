#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000010];


int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if((s[i]-48)>=0 && (s[i]-48)<=9)
		{
			
			num[i]=s[i]-48;
			n++;	
		}
	}
	
	sort(num,num+1000010);
	
	for(int i=1000009;i>1000009-n;i--)
		cout<<num[i];
	cout<<endl;
	
	
	
	return 0;
}
