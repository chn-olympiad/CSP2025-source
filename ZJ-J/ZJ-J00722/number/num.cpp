#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	int len=s.length();
	int t=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++t] = s[i]-'0';
		}
	}
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
