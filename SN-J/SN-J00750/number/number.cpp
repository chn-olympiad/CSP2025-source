#include <bits/stdc++.h>
using namespace std;
int number[100005],cnt;
string app="";
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int q=int(s[i])-48;
			number[cnt]=q;
			cnt++;
		}
	}sort(number,number+cnt);
	for(int i=cnt-1;i>=0;i--){
		app+=char(number[i]+48);
	}cout<<app;
	return 0;
} 
