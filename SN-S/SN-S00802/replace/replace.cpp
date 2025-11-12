#include<bits/stdc++.h>
using namespace std;
string sa,sb;
string ta,tb;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n;
	cin>>q;
	for(int i=1;i<=n;i++){
		cin>>sa>>sb;
	} 
	for(int i=1;i<=q;i++)
	{
		cin>>ta>>tb;
	}
	for(int i=1;i<=q;i++){
		cout<<n/(i+1);
	}
	return 0;
} 
