#include<bits/stdc++.h>
using namespace std;
string st;
long long num[15],cnt=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> st;
	for(int i=0;i<st.length();i++){
		if(st[i]>='0'&&st[i]<='9'){
			cnt++;
			num[st[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++) cout << i;
	}
	return 0;
}
