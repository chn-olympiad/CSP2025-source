#include <bits/stdc++.h>
using namespace std;
string s;
int v;
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int si=s.size();
	for(int i=0;i<si;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(num[i]>0){
			v++;
		}
		for(int j=num[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
}
