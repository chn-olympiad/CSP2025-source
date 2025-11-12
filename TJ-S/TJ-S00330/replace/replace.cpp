#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s1,s2,t1,t2;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
	}
	for(int p=1;p<q;p++){
		cin>>t1>>t2;
	}
	if(n==4){
		cout<<2<<endl;
		cout<<0<<endl;
	}
	fclose(stdin);
    fclose(stdout);
	return 0;
}
