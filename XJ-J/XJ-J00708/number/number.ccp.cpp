#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n=s.size();
	int a[n];
	for(int i=0;i<s.size();i++)
    {
    	if(s[i]>='0'&&s[i]<='9')
    	{
    		a[i]=s[i]-48;
		}
	}
	int  a[m];
	for(int i<0;i<s.size();i++)
	{
		int x=0;
		if(s[i]>='0'&&s[i]<='9')
    	{
    		a[i]=s[i]-48;
    		cout<<a[i]<<" "<<endl;
    		
		}
	}
	sort(a,a+n)
	for(int i=0;i<m;i++)
	{
		cout<<a[i];
	}
	
	return 0;
}
