#include<bits/stdc++.h>
using namespace std;
int a,i,j,k,num[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[(int)(s[i]-'0')]++;
		}
	}for(i=9;i>=0;i--){
		for(j=1;j<=num[i];j++){
			cout<<i;
		}
	}
	return 0;
}
