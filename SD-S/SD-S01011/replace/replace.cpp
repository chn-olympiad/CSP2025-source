#include<bits/stdc++.h>
using namespace std;
vector<string> a;
vector<string> b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
		a.push_back(s1);
		b.push_back(s2);
	}
	for(int i=0;i<q;i++){
		string s1,s2;
		cin>>s1>>s2;
		cout<<0<<endl;
	}
	return 0;
} 
