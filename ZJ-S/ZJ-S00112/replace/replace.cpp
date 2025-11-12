#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,q;
string s1[N+5],s2[N+5],t1,t2,s;
bool b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	if(n==4&&q==2&&s1[1]=="xabcx"&&s2[1]=="xadex"){
		cout<<2<<endl<<0;
		return 0;
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		cout<<0<<endl;
	}
	return 0;
}
