#include<bits/stdc++.h>
using namespace std;
char a[110];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		int n=0;
		n=s[i];
		if('0'<=n&&n<= '9'){
			cout<<s[i];
			a[i]=s[i];
		}
	}
	sort(a,a+1);
	for(int i=0;i<s.size();i++){
		cout<<a[i];
	}
	return 0;
} 
