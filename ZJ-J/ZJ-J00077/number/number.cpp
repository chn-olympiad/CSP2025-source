#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i]))a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=a[i];j>=1;j--){
			cout<<i;
		}
	}
	return 0;
}

