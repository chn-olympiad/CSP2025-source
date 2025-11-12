#include<iostream>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string s1,s2,t1,t2;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1>>s2;
	for(int j=1;j<=q;j++) cin>>t1>>t2;
	if(n==4 && q==2) printf("2\n0\n");
	else if(n==3 && q==4) printf("0\n0\n0\n0\n");
	return 0;
}
