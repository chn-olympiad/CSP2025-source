#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n = 0;
	int a[s.size()];
	for(int i = 0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n);
	int t = 0;
	for(int i = n-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}

