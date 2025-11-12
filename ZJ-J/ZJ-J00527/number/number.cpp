#include<bits/stdc++.h>
#define lon long long
using namespace std;
int n;//1e6
char st[1000010];
int gs[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>st+1;
	n=strlen(st+1);
	for(int i=1;i<=n;i++){
		if(st[i]>='0' && st[i]<='9') gs[st[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=gs[i];j++){
			cout<<(char)('0'+i);
		}
	}
	return 0;
}
