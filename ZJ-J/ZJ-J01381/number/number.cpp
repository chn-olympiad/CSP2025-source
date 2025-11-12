#include<bits/stdc++.h>
using namespace std;
string s;
int len=0,a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof(a));
	getline(cin,s);
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			printf("%d",i);
			a[i]--;
		}
	}
	return 0;
}