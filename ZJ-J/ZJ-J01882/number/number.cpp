#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int cnt[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if('0'<=s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]>0){
			cout<<i;
			cnt[i]--;
		}
	}
	return 0;
} 

