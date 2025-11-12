#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
long long int len,t[15];
void sw(){
	for(int i=0;;i++){
		if(s[i]==' '){
			return;
		}
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sw();
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	return 0;
}
