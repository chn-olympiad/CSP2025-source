#include<bits/stdc++.h>
using namespace std;
string s;	
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length(),b[100001],t=1;
	for(int i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9'){
			b[t]=s[i]-'0';
			t++;
		}
	}
	sort(b+1,b+t+1);
	for(int i=t;i>1;i--){
		cout<<b[i];
	}
	return 0;
}
