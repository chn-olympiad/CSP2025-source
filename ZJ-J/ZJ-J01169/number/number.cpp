#include<bits/stdc++.h>
using namespace std;
char s[1000005];
string a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	for(int i=1;i<=1000000;i++){
		if('0'<=s[i]&&s[i]<='9')a[s[i]-'0']+=s[i];
	}
	for(int i=9;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
