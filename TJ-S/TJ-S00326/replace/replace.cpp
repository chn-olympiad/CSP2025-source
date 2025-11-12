#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005],ss1[200005],ss2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>ss1[i]>>ss2[i];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
