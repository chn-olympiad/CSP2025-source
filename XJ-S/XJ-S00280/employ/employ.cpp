#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
	int arr[505],sum=0;
int main(){	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=s.size();i++)
	{
		if(s[i]=='1')
			sum++;
	}
	if(sum==s.size())
		cout<<0;
		
	
	
	

	return 0;
}
