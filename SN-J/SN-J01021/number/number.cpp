#include<bits/stdc++.h>
using namespace std;
string s;
long int n[1000000],l,d;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>=48&&s[i]<=57){
			n[d++]=int(s[i]-48);
		}
	}
	sort(n,n+l,cmp);
	for(int i=0;i<d;i++){
		cout<<n[i];
	}
	return 0;
}
