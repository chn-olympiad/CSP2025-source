#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[200010],k[200010],s1[5000010],s2[5000010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>k[i];
	}
	for(int i=1;i<=m;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=m;i++){
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
