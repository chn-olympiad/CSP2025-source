#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

string s;
int a[1000005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		a[i]=-1;
		if( s[i]>='0' && s[i]<='9' ){
			a[i]=s[i]-'0';
		}
	}
	sort(a,a+len);
	for(int i=len-1;i>=0;i--){
		if(a[i]!=-1){
			cout<<a[i];
		}
		else return 0;
	}
	return 0;
}
