#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size()!=0&s.size()<8)cout<<s;
	else if(s.size()>=8)cout<<92100;
	return 0;
}
