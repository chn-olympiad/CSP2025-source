#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],at=0,t[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++at]=s[i]-'0';
			t[a[at]]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++)printf("%d",i);
	}
	return 0;
}
