#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int a[1000001];
int n=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s[i]!=0;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a+1,a+n+1);
	if(a[n]==0){
		cout<<0;
		return 0;
	}
	for(int i=n;i>1;i--){
		cout<<a[i];
	}
}