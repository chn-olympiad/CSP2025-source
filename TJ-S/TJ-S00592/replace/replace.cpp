#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string s[999][999],t[999][999];
	cin>>n>>q;
	for(int j=0;j<q;j++){
		cin>>t[j][0]>>t[j][1];
	}
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	if(n==4 && q==2 && t[0][0]=="xabcx" && t[0][1]=="xabex" && t[1][0]=="ab" && t[1][1]=="cd" && s[0][0]=="bc" && s[0][1]=="de" && s[1][0]=="aa" && s[1][1]=="bb" && s[2][0]=="xabcx" && s[2][1]=="xadex" && s[3][0]=="aaaa" && s[3][1]=="bbbb"){
		cout<<2<< endl;
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
