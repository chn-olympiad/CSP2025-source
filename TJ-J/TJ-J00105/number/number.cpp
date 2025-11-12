#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000002];
long long n;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//define long long long long
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++n]=s[i]-'0';
		}
	}
	sort(a+1,a+1+n,cmp);
	for(long long i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}
