#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	long long cnt=0;
	cin>>s;
	long long len=s.size();
	for(long long i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9')a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+1+cnt,greater<int>());
	for(long long i=1;i<=cnt;i++){
		cout<<a[i];
	}
	cout<<'\n';
	return 0;
}
