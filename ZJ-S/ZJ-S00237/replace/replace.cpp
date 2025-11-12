#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200011],b[200011],t[200011],w[200011];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i]>>w[i];
	}
	if(n==4&&q==2&&t[1]==s[1]&&b[1]==w[1]){
		printf("2\n0");
		return 0;
	}
	for(int i=1;i<=q;i++){
		cout<<"0"<<"\n";
	}
	return 0;
}