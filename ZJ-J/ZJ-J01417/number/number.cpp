#include<bits/stdc++.h>
#define int long 

using namespace std;

const int N=1e6+10;

char s[N];
int cnt[20];

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	freopen("number.in","r",stdin); freopen("number.out","w",stdout);
 	cin>>s+1; int len=strlen(s+1);
 	for(int i=1;i<=len;i++){
 		if('0'<=s[i]&&s[i]<='9') cnt[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]>0){
			cout<<i; cnt[i]--;
		}
	} 
	return 0;
}
