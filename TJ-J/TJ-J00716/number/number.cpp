#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
	string n;
	long long int a[200005]={0},p=0;
	cin>>n;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<n.length();i++)
	{
		if(n[i]=='0'||n[i]=='1'||n[i]=='2'||n[i]=='3'||n[i]=='4'||n[i]=='5'||n[i]=='6'||n[i]=='7'||n[i]=='8'||n[i]=='9')
		{
			p++;
			a[p]=n[i]-'0';
		} 
	}
	sort(1+a,1+a+p);
	for(int i=p;i>=1;i--)
	{
		cout<<a[i];
	}cout<<endl;
	return 0;
}
