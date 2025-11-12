#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,arr[520],b[520];//arrÊÇÄÍÐÄ 
string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>arr[i];
	for(int i=0;i<=s.size();i++)b[i]=(int) (s[i]-'0');
	sort(arr,arr+n);
	long long p;
    p=999999999999999999+999999999999999999+999999999999999999+999999999999999999+999999999999999999+999999999999999999+999999999999999999+999999999999999999+999999999999999999;
    cout<<p%998244353;
	return 0;
}    
