#include <iostream>
#include <cstdio>
using namespace std;
int n,q;
string s[210000][5],t[210000][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++)cin>>t[i][1]>>t[i][2];
	for(int i=1;i<=n;i++){
		int cc=0;
		for(int j=0;i<s[i][1].size();i++){
			if(s[i][1][j]!='a'||s[i][1][j]!='b'){
				cout<<0<<endl;
				break;
			}
			else{
				if(s[i][1][j]=='a'||s[i][1][j]=='b')cc++;
				
			}
		}
		cout<<cc<<endl;
	}
	return 0;
}
