#include<bits/stdc++.h>
using namespace std;
string s1;
char c[1000005];
long long t=0;
bool cmp(char x,char y){
	return x<y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9') c[++t]+=s1[i];
	}
	sort(c+1,c+t+1,cmp);
	while(t){
		cout<<c[t];
		t--;
	}
	return 0;
}