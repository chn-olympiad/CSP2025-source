#include<bits/stdc++.h>
using namespace std;
string s1,s2,s;
int main(){
	int n,q;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1>>s2; 
	}
	for(int i=0;i<q;i++){
		cin>>s1>>s2;
		if(s1.size()<s2.size()){
			cout<<0<<endl;
		}
		else cout<<i<<endl;
	} 
	return 0;
}

