#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int len=s.size();
	string t;
	int c[10],cnt=0;
	memset(c,0,sizeof(c));
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(c[i]==0&&i!=0){
			cnt++;
		}
		if(i==0&&cnt==9){
			cout << 0;
			return 0;
		}
		for(int j=0;j<c[i];j++){
			cout << i;
		}
	}
	return 0;
}
