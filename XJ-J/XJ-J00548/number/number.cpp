#include<bits/stdc++.h>
#include<cstdio>
int shu[1000005];
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			s[i]=shu[i];
			sort(shu+1,shu+s.size()+1);
			cout<<shu[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
