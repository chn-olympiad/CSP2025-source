#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int si=s.size(),jsd=0;
	int a[100001];
	for(int i=0;i<=si;i++){
		if(s[i]>='0'&&s[i]<='9'){ 
			a[i]=int(s[i])-48;
			jsd++;
		}
		else continue;
	}
	sort(a,a+si,cmp);
	for(int i=0;i<jsd;i++){
		cout<<a[i];
	}
	return 0;
}
