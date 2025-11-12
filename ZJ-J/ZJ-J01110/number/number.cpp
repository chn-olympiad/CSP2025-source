#include<bits/stdc++.h>
using namespace std;
const int Maxn=1000005;
string s;
int a[Maxn];
int len=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		int t=int(s[i]-'0');
		if(t>=0 && t<=9) a[++len]=t;
	}
	sort(a+1,a+1+len);
	for(int i=len;i>=1;i--) cout<<a[i];
	return 0;
}
