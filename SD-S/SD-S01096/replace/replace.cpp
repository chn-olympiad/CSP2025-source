#include<bits/stdc++.h>
using namespace std;
string s[100010][2],str[2];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		cin>>str[0]>>str[1];
		if(str[0].size()!=str[1].size()){
			cout<<0<<endl;
			continue;
		}
		int l=0,r=str[0].size()-1;
		while(str[0][l]==str[1][l])l++;
		while(str[0][r]==str[1][r])r--;
		long long cnt=0;
		for(int le=0;le<=l;le++){
			for(int i=1;i<=n;i++){
				int noww=0;
				for(;noww<s[i][0].size();noww++){
					if(s[i][0][noww]!=str[0][le+noww]||s[i][1][noww]!=str[1][le+noww])break;
				}
				if(le+noww>r&&noww==s[i][0].size())cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

