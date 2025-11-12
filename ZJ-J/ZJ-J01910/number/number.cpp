#include<bits/stdc++.h>
using namespace std;
string s;
long long bucket[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size()-1;
	for(int i=0;i<=len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			int num=s[i]-'0';
			bucket[num]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(bucket[i]--)cout<<i;
	}
	return 0;
}