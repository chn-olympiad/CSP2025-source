#include<bits/stdc++.h>
using namespace std;
int l[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			l[n]=s[i]-'0';
			n++;
		}
	}
	sort(l,l+n);
	for(int i=n-1;i>=0;i--){
		cout<<l[i];
	}
	return 0;
}
