#include<bits/stdc++.h>
using namespace std;
int a[15]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	bool f=false;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(i==0&&!f){
			cout<<0;
			break;
		}
		while(a[i]>0){
			if(i!=0&&!f)f=true;
			cout<<i;
			a[i]--;
		}
	}
}
