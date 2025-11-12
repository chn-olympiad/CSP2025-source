#include <bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
} 
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,shu;
	cin>>s;
	int chang=s.size();
	for(int i=0;i<chang;i++){
		if(s[i]>='0' && s[i]<='9'){
			shu+=s[i];
		}
	}
	sort(shu.begin(),shu.end(),cmp);
	cout<<shu;
	return 0;
}
