#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int t[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(isdigit(s[i])) t[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(t[i]){
			for(int j=1;j<=t[i];j++) cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
