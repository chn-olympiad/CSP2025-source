#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	int t=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=s[i]-'0';
			t++;
		}
	}
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++){
		cout<<a[i];
	}
	return 0;
}
