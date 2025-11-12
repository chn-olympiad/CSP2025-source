#include<bits/stdc++.h>
using namespace std;
string s;
const long long N=1e6+10;
int a[N];
long long t;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			t++;
			a[t]=int(s[i])-'0';
		}
	}
	sort(a+1,a+t,cmp);
	for(int i=1;i<=t;i++){
		cout<<a[i];
	}
	return 0;
}
