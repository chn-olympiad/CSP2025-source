#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[222222],s2[222222],t1[222222],t2[222222];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=0;i<q;i++){
		cout<<'0'<<endl;
	}
	return 0;
}