#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int l,d[10];
int main(){
	freopen("number.in ","r",stdin);
	freopen("number.out ","w",stdout);
	cin>>(s+1);
	l=strlen(s+1);
	for(int i=1;i<=l;i++){
		if(s[i]=='0'||(s[i]>='1'&&s[i]<='9')){
			d[s[i]-'0']++;
		}
	}
	int f=0;
	for(int i=9;i>=0;i--){
		if(f==0&&i==0){
			cout<<"0"<<endl;
			continue;
		}
		while(d[i]>0){
			d[i]--;
			cout<<i;
			f=1;
		}
	}
	return 0;
}