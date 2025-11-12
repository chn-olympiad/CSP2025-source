#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline (cin,s);
	for(int i=1;i<=s.size();i++){
		cin>>s[i];
		if(i>'0'||i<'10'){
			cout<<s;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
