#include<bits/stdc++.h>
using namespace std;
int p=1;
int num[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for (int x=0;x<len;x++){
		if(s[x]>='0'&&s[x]<='9'){
			num[p++]=s[x]-'0';
		}
	}
	sort(num+1,num+p);
	for (int x=p-1;x>0;x--){
		cout<<num[x];
	}
	return 0;
} 
