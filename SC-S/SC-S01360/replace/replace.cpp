#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[(int)2e5+10][3];
int main(){

	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int i=1;i<=2;i++){
			cin>>s[n][i];
		}
	}
	string t1,t2;
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

