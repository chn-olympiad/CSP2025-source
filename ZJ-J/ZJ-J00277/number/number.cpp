#include<bits/stdc++.h>
using namespace std;
int num[1000001],numm=0,zero=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[++numm]=s[i]-'0';
		}
	}
	sort(num+1,num+1+numm);
	for(int i=numm;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}
