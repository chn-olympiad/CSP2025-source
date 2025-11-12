#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.cpp","r",stdin);
	freopen("replace.cpp","w",stdout);
	int n,q;
	cin>>n>>q;
	int s1[n],s2[n],t1[q],t2[q];
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<q;j++){
			cin>>t1[j]>>t2[j];
		}
	}
	cout<<t1[n];
	return 0;
} 
