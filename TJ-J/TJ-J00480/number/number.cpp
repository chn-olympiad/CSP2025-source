#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int b=s.length();
	int n[b];
	int a=0;
	for (int i=0;i<s.length();i++){
		if (s[i]>=48  && s[i]<=57){
			n[a]=s[i];
			a++;
		}
	}
	for (int i=0;i<a;i++){
		n[i]-='0';
	}
	sort(n,n+a);
	for (int i=a-1;i>=0;--i){
		cout<<n[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
