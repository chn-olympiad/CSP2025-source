#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,q;
const int N=2e5+10;
string s1[N],s2[N],t1[N],t2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int a=1;a<=n;a++){
		cin>>s1[a]>>s2[a];
	}
	for(int a=1;a<=q;a++){
		cin>>t1[a]>>t2[a];
	}
	return 0;
} 
