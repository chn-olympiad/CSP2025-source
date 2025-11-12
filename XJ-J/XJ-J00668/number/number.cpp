#include <bits/stdc++.h>
using namespace std;
string str;
string brr;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>str;
	int xbuuu=0;
	sort(str.begin(),str.end());
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			brr[xbuuu]=str[i];
			 xbuuu++; 
					}
	} 

	for(int i=xbuuu-1;i>=0;i--){
		cout<<brr[i];
	}
	 
	return 0;
}
