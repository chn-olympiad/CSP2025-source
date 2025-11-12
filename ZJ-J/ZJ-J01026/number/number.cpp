#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int n;
char s[N];
int cnt[20];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",(s+1));
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if('0'<=s[i]&&s[i]<='9') cnt[s[i]-'0']++;
	}
	//cout<<num<<endl;
//	for(int i=0;i<=9;i++) cout<<cnt[i]<<" ";
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			putchar(i+'0');
		}
	}
	return 0;
}
