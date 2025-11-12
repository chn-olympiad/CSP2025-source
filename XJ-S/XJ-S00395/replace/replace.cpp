#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,q,ls[200000],ly[200000];
	string s[200000],y[200000];
	cin>>n>>q;
	for (int i=0;i<n;i++){
		cin>>s[i];
		ls[i]=s[i].length();
	}
	for (int i=0;i<q;i++){
		cin>>y[i];
		ls[i]=s[i].length();
	}
	for (int i=0;i<q;i++){
		for (int j=0;j<n;j++)
			if(ly[i]>=ls[j] && i!=j)
	}
	return 0;
}
