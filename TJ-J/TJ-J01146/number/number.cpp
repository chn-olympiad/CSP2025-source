#include<bits/stdc++.h>

using namespace std;
string s;
long long b;
char a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[b]=s[i];
			b++;
		}
	}
	sort(a,a+b);
	for(int i=b-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
