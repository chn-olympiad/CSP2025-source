#include<bits/stdc++.h>
using namespace std;
int a[2000001];
string s;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>s;
	int sign=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[sign]=int(s[i])-48;
			sign++;
		}
	}
	sort(a+1,a+sign,cmp);
	bool flag=0;
	for(int i=1;i<=sign-1;i++){
		if(a[i]!=0){
			flag=1;
			break;
		}
	}
	if(!flag){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=sign-1;i++){
		cout<<a[i];
	}
	return 0;
}
