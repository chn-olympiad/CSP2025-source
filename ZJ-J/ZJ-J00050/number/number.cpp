#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;

int n,tot[15];
char s[maxn];
bool fr;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s+1;
	n=strlen(s+1);
	for (int i=1;i<=n;i++){
		if (s[i]>='0' && s[i]<='9'){
			tot[s[i]-'0']++;
		}
	}
	fr=true;
	for (int i=9;i>=0;i--){
		for (int j=1;j<=tot[i];j++){
			cout<<i;
			if (fr && i==0){
				break;
			}
			fr=false;
		}
	}
	return 0;
}
