#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end());
	for(int i=s.size()-1;i>=0;i--)
		if(s[i]<='9' && s[i]>='0') 
		    cout<<s[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
