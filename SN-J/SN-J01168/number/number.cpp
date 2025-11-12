//SN-J01168 ¬нич–щ 
#include <bits/stdc++.h>
using namespace std;
int a[50];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if((s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='z')){
			if(s[i]>='0' && s[i]<='9') a[(s[i]-'0')]++;
		}else{
			break;
		}
	}
	for(int i=9;i>=0;i--){
		int n=a[i];
		for(int j=1;j<=n;j++){
			cout << i;
		}
	}
	return 0;
}
