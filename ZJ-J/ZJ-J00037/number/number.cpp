#include<bits/stdc++.h>

using namespace std;
string s;
int l=0,aaa=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);


	cin>>s;
	while(s[l]!=NULL){
		l++;
	}
	char a[l];
	for(int i=0;i<l;i++){
		if(s[i]<'a'){
			a[aaa]=s[i];
			aaa++;
		}
	}
	sort(a,a+aaa+1);
	for(int i=aaa;i>=0;--i){
		cout<<a[i];
	}
	
	return 0;
}
