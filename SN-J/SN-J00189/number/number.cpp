#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	for(int j=s.size()-1;j>=0;j--){
		cout<<s[j];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
