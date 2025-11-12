#include<bits/stdc++.h>
using namespace std;
char str[1145141];
vector<int> lst;
int outl[111],save;
signed main(){
	freopen("number.in","r+",stdin);
	freopen("number.ans","w+",stdout);
	cin>>str;
	int i=0;
	while(str[i]!=0){
		if('0'<=str[i]&&'9'>=str[i]){
			lst.push_back(str[i]-'0');
			outl[str[i]-'0']++;
		}
		i++;
	}
	for(int i=1;i<=9;i++){
		save+=outl[i];
	}
	if(save==0){
		cout<<0;return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=outl[i];j++){
			cout<<i;
		}
	}
}
