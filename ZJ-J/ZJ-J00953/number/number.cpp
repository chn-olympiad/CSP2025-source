#include<bits/stdc++.h>
using namespace std;
string s;
int len;
int tong[15];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			tong[s[i]-'0']++;
		}
	}for(int i=9;i>=0;i--){
		for(int j=1;j<=tong[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}
