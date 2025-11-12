#include<bits/stdc++.h>
using namespace std;
string s;
int arr[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9') arr[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=arr[i];j>=1;j--) cout<<i;
	}
	return 0;
}
