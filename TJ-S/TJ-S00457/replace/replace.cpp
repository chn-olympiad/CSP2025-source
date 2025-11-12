#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;
int n,q;
condt int p = 200005;
string s1[p];
string s2[p]; 
string t1[p];
string t2[p];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> s1[i] >> s2[i];
	}
	for(int j = 1;j <= q;j++)
	{
		cin >> t1[j] >> t2[j];
	}
	
	
	return 0;
}
