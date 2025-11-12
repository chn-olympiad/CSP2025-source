#include<bits/stdc++.h>
using namespace std;
int n;
char s[1000010];
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0') cnt[s[i]-'0']++;
	}
	bool flg=0;
	for(int i=9;i>=0;i--){
		if(i>0&&cnt[i]>0) flg=1;
		if(i==0&&!flg){
			cout<<0;
			break;	
		}
		for(int j=1;j<=cnt[i];j++){
			putchar('0'+i);
		}
	}
	return 0;
}
