#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,ct,nm,c[N],p[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s,s=" "+s;
	for(int i=1;i<=n;i++)cin>>c[i],p[i]=i;
	do{
		nm=0;
		for(int i=1;i<=n;i++){
			if(nm>=c[p[i]])nm++;
			else if(s[i]=='0')nm++;
		}
		if(n-nm>=m)ct++; 
	}while(next_permutation(p+1,p+1+n));
	cout<<ct;
	return 0;
}
