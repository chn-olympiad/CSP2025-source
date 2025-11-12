#include <bits/stdc++.h>
using namespace std;
int a[100005];
int qaz(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),cnt=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[i+1]=s[i]-'0';
			if(a[i+1]==0) cnt++;
		}
	}
	sort(a+1,a+l+1,qaz);
	for(int i=1;i<=l;i++){
		if(a[i]!=0){
			cout<<a[i];
		}
	}
	for(int i=1;i<=cnt;i++){
        cout<<0;
	}
	return 0;
}