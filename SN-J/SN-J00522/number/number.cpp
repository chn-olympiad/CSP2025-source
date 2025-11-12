//SN-J00522 李宸昊  西安市曲江第一学校 
#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define ll long long 
#define inf 0x3f3f3f3f
const int maxn=1e6+5;
int n=0,a[maxn];
string s;
bool cmd(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	rep(i,0,s.size()-1){
		if(s[i]>='0'&&s[i]<='9') a[++n]=int(s[i]-'0');
	}
	sort(a+1,a+1+n,cmd);
	rep(i,1,n) cout<<a[i];
	return 0;
}
