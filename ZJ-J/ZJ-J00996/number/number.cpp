#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char c[N];
int cnt[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>(c+1);
	int n=strlen(c+1);
	for(int i=1;i<=n;i++){
		if(c[i]>='0'&&c[i]<='9'){
			cnt[c[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]){
			cnt[i]--;
			cout<<i;
		}
	}
	return 0;
}