#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=1;i<=len-1;i++){
		if(i>='0'&&i<='9'&&i<=len){
			cout<<i;
		}
	}
	return 0;
}
