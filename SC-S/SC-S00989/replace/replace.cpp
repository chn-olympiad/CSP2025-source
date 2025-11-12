#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
int n,q,s2;
string s[10000][10],t[20000][10],x[10000],y[10000],z[10000],s1[10000];
cin>>n>>q;
cin>>s[n][2];
cin>>t[q][2];
for(int i=0;i<=n;i++){
	for(int j=0;j<=q;j++){
s1[n]=x[i]+y[j]+z[n-i-j];
		t[i][j]=x[i]+s[i][j]+z[j];
	}
}
while(q<=0){
	cout<<s2<<'\n';
	q--;
}
	return 0;
}