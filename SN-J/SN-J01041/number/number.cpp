#include<bits/stdc++.h>
using namespace std;

long long a[1000010];

struct node
{
	long long da;
}mi[1000010];

bool cmp(node a,node b)
{
	return a.da >b.da;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long ans=0;
	cin>>s;
	long long len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			mi[i].da=s[i]-'0';
			ans++;
		}
	} 
//	if(mi[0].da%10==mi[0].da)
//	{
//		for(int i=0;i<ans;i++)
//		{
//			cout<<mi[0].da;
//		 } 
//		
//		return 0;
//	 } 
	sort(mi,mi+len,cmp);
	for(int i=0;i<ans;i++)
	{
		cout<<mi[i].da;
	}
	
	
	return 0;
 } 
