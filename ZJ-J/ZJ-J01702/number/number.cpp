#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid(l,r) (l+r>>1)
#define lowbit(x) (x&-x)
using namespace std;
const int N=1e6+10,M=1+10,mod=1e9+7;
const double eps=1e-1;
const long double pi=acos(-1);
string s;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i]))a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1,cmp);
	if(a[1]==0)cout<<"0"<<endl;
	else{
		for(int i=1;i<=cnt;i++)cout<<a[i];
		cout<<endl;
	}
	return 0;
}
