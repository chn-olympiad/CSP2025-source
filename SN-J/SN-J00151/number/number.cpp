#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s[1000000];
	int t,max=0,c=sizeof(s);
	for(int i=0;i<=c-1;i++){
		cin>>s[i];
	}
	for(int i=0;i<=c-1;i++){
	if(c==1&&s>='0'&&s<='9'){
		cout<<s[i];
		return 0;
		}
	else{
	for(int i=0;i<=c-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			sort(s[i],s[i]+c);
		}
	}
	for(int i=0;i<=c-1;i++){
		cout<<s[i];
	}
}
}
	return 0;
}
