#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=1e6+5;
const int eps=1e-6;
const int mod=1e9+7;
int read(){
	int k=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		k=k*10+ch-'0';
		ch=getchar();
	}
	return k*f;
}
int a[N],cnt;
void solve(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++cnt]=s[i]-'0';
	sort(a+1,a+1+cnt,greater<int>());
	for(int i=1;i<=cnt;i++)cout<<a[i];
	cout<<'\n';
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
