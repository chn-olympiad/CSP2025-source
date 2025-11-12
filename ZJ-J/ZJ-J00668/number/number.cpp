#include<bits/stdc++.h>
using namespace std;
string a;
int n,op[10000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.length();
	for(int i=0;i<n;i++)
	{
		if(a[i]-'0'>=0)
		{
		    op[a[i]-'0']++;
	    }
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=op[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
