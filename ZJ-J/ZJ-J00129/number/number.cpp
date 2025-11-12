#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],p=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++p]=s[i]-'0';
		}
	}
	sort(a+1,a+p+1,cmp);
	if(a[1]==0&&a[p]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=p;i++){
		cout<<a[i];
	}
	return 0;
}

