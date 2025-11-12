#include<bits/stdc++.h>
using namespace std;
int a[1000005],t=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		char x=s[i];
		if('0'<=x&&x<='9'){
			a[++t]=(x-'0');
		}
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++){
		cout<<a[i];
	}
	return 0;
}
