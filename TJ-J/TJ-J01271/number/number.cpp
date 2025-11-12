#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int idx=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++idx]=s[i]-'0';
		}
	}
	sort(a+1,a+idx+1,cmp);
	for(int i=1;i<=idx;i++){
		cout<<a[i];
	}
	return 0;
}

