#include <bits/stdc++.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a[s.size()+1];
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[i]=s[i]-'A'+17;
		else a[i]=11;
	}
	for(int i=0;i<s.size();i++){
		for(int j=i+1;j<s.size();j++){
			if(a[i]!=11&&a[j]!=11){
				if(a[i]<a[j]) swap(a[i],a[j]);
			}
		}
	}
	for(int i=0;i<s.size();i++){
		if(a[i]!=11) cout<<a[i];
	} 
	return 0;
}
