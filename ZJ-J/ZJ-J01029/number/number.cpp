#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+1e2;
int len;
int a[N],cnt;
string str;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	len=str.size();
	for(int i=0;i<len;i++)
		if(str[i]>='0'&&str[i]<='9') a[++cnt]=str[i]-'0';
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++) cout<<a[i];
	return 0;
}
