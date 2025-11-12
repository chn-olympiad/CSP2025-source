#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
char s[maxn];
int t[15],d;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int sl=strlen(s);
	for(int i=0;i<sl;i++){
		if(s[i]>='0'&&s[i]<='9')t[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++)cout<<i;
	}
	return 0;
}
