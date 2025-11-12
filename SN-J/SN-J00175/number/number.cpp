//SN-00175 叶明哲 延安市安塞区高级中学 
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
freout(input.in;"number.in";in)
freout(output.out;"number.out";out)
int main()
{
	string s;
	string c;
	string d;
	cin>>s;
	int a[10000];
	int f[10000];
	int g=0;
	int h=0;
	for(int i=0;i<s.size();i++) a[i]=s[i];
	for(int j=0;j<s.size();j++) if(a[j]>=48 && a[j]<=57) c[j]=s[j];
	for(int i=0;i<c.size();i++)
	{
		for(int j=i;j<c.size();j++) if(c[j]>c[i]) g=c[j];
		h=c[i];
		c[i]=g;
		c[j]=h;
	}
	for(int i=0;i<c.size;i++) cout<<c[i];
	return 0;
}
