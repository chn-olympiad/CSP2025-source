#include<bits/stdc++.h>
using namespace std;
long long num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') num[0]++;
		if(s[i]=='1') num[1]++;
		if(s[i]=='2') num[2]++;
		if(s[i]=='3') num[3]++;
		if(s[i]=='4') num[4]++;
		if(s[i]=='5') num[5]++;
		if(s[i]=='6') num[6]++;
		if(s[i]=='7') num[7]++;
		if(s[i]=='8') num[8]++;
		if(s[i]=='9') num[9]++;
	}
	for(int i=9;i>=0;i--){
		while(num[i]--){
			cout<<i;
		}
	}
	return 0;
}

