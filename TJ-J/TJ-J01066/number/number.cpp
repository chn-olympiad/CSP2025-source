#include<bits/stdc++.h>
using namespace std;
int n[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='a'&&s[i]<='z') continue;
		int num=int(s[i]-'0');
		n[num]++;
	}
	for(int i=9;i>=0;i--){
		while(n[i]>0){
			printf("%d",i);
			n[i]--;
		}
	}
	return 0;
}
