#include<bits/stdc++.h>
using namespace std;
string str;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9') a[str[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++) cout<<i;
	}
	return 0;
}