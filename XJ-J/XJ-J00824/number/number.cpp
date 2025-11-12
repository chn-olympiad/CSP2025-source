#include<bits/stdc++.h>//number
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	long long int i,len,s[1000005]={0};
	cin>>a;
	len=a.size();
	
	for(i=0;i<len;i++)
	  if(a[i]>='0'&&a[i]<='9') 
	    s[a[i]-'0']++;//若果是，则对应的s数组数量+1 
	for(i=9;i>=0;i--)
	{
		if(s[i]!=0)
		  while(s[i]--)
		  {
		  	cout<<i;
		  }
	}
	return 0;
	
}
