#include<bits/stdc++.h>
using namespace std;
string s;
int aa[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			aa[l++]=s[i]-'0';
		}
	}
	sort(aa+1,aa+l);
	for(int i=l-1;i>=1;i--){
		cout<<aa[i];
	}
	return 0;
}

