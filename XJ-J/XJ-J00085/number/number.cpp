#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int cnt,a[N];
string s;
int main() {
	freopen("number.in","r"stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int n=len-1;
	for(int i=0;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+1+n,greater<int>());
	for(int i=0;i<=cnt-1;i++){
		cout<<a[i];
	}
	return 0;
}
