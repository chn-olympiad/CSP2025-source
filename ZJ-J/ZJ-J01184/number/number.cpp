#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans="";
	cin>>s;
	int a[10]={},n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++)ans+=i+'0';
	}
	cout<<ans<<endl;
	return 0;
}
