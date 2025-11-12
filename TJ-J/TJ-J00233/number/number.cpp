#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	string s;
	int a[111111];
	long long b=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[b]=s[i]-'0';
			b++;
		}
	}sort(a,a+b);
	for(int i=b-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
