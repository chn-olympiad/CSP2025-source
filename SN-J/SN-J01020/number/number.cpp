//赵柏然-SN-J01020-曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int a[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int c=0;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[c]=s[i]-'0';
			c++;
		}
	}
	sort(a,a+c);
	for(int i=c-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
