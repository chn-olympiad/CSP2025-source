#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,-1,sizeof(a));
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9') a[i]=s[i]-'0';
	}
	sort(a,a+s.length());
	for(int i=s.length()-1;a[i]!=-1;i--){
		cout<<a[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
