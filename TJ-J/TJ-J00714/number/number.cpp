#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ss;
	cin>>s;
	int n,nn;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0' and s[i]<='9')
		ss+=s[i];
	}
	nn=ss.size();
	for(int i=0;i<=nn-1;i++){
		for(int j=0;j<nn-1;j++){
		if(ss[j]<ss[j+1])
		swap(ss[j],ss[j+1]);
	}
	}
	cout<<ss;
	return 0;
} 
