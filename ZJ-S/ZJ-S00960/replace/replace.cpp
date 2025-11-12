#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=2e5+1;
string s1[N],s2[N];
string t1[N],t2[N];
main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=q;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(t1[i].find(s1[i])!=-1)cnt++;
		}
		cout<<cnt<<'\n';
	}
}
