#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000000;
string s;
int a[MAXN+5];
bool cmp(int a,int b){
	return a>b&&a>-1;
}
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=MAXN+5;i++){
		a[i]=-1;
	}
	cin>>s;
	int now=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			now++;
			a[now]=s[i]-'0';
		}
	}
	sort(a+1,a+now+1,cmp);
	for(int i=1;i<=now;i++){
		cout<<a[i];
	}
	return 0;
}
