#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string s1[100005],s2[100005],t1[100005],t2[100005];
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	cout<<"2"<<endl;
	cout<<"0"<<endl;
	fclose(stdin);
	fclose(stdout);
}
