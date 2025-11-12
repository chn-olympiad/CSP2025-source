#include<bits/stdc++.h>
using namespace std;
string n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n+=s[i];
		}
	}
	int m=n.length();
	char a;
	for(int i=0;i<m-1;i++){
		for(int j=i+1;j<m;j++){
			if(n[i]<n[j]){
				a=n[i];
				n[i]=n[j];
				n[j]=a;
			}
		}
	}
	cout<<n;
	return 0;
} 
