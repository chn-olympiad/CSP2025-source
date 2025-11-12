#include<bits/stdc++.h>
using namespace std;
string s;
int mm=0,t;
int main(){
	//freopen("number.in","r",stdin);
	cin>>s;
	int a[s.size()+5];
	for(int i=0;i<= s.size();i++)
	{
		if(s[i]<='0' && s[i]>='1')
		{
			a[mm]=s[i];
			mm++;
		}
	}
	for(int i=0;i<=mm;i++)
	{
		for(int j=1;j<=mm;j++)
    	{
	    	if(a[j]>a[j-1])
	    	{
	    		int t=0;
	    		t=a[j];
	    		a[j]=a[j-1];
	    		a[j-1]=t;
			}
	    }
	}
    for(int i=0;i<=mm;i++)
	{
		cout<<a[i];
	}
	return 0;
}
