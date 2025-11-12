#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1000005;
long long n,f[15]={};
bool flag=false;
char s[MAXN];
void solve(){
	cin>>s+1;
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			f[s[i]-'0']++;
		}
	}
	for(int i=9;i>0;i--){
		for(int j=1;j<=f[i];j++){
			cout<<i;
			flag=true;
		}
	}
	if(!flag){
		cout<<0<<"\n";
	}else{
		for(int i=1;i<=f[0];i++){
			cout<<0;
		}
		cout<<"\n";
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}