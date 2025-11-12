#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string a;
    getline(cin,a);
    sort(a.begin(),a.end());
    
    for(int i=a.size()-1;i>=0-1;i--)
    {
    	
    	if(a[i]!='a' && a[i]!='b' && a[i]!='c' && a[i]!='d' && a[i]!='e' && a[i]!='f' && a[i]!='g' && a[i]!='h' && a[i]!='i' && a[i]!='j' && a[i]!='k' && a[i]!='l' && a[i]!='m' && a[i]!='n' && a[i]!='o' && a[i]!='p' && a[i]!='q' && a[i]!='r' && a[i]!='s' && a[i]!='t' && a[i]!='u' && a[i]!='v' && a[i]!='w' && a[i]!='x' && a[i]!='y' && a[i]!='z' && a[i]!=' ')
    	{
    		cout<<a[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


