#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number4.in","r",stdin);
	freopen("number4.out","w",stdout);
	string s;
	string s2;
	int c=0;
	cin>>s;
	for(int i=0;i<=s.length();i++){
		if(isdigit(s[i])){
			s2+=s[i];
			c++;
		}
	}
	int n=s2.length();
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			if(s2[j]<s2[j+1])swap(s2[j],s2[j+1]);
		}
	}
	cout<<s2;
	return 0;
}
