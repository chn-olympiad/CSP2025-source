#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0' and s[i]<='9'){
		cout<<s[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
