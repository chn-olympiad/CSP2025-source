#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,t,b[1000010];
string a;
bool cmp(int q,int h){
	return q>h;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a;
	for(i=0;i<a.size();i++)
		if(a[i]>='0'&&a[i]<='9')b[++t]=a[i]-48;
	sort(b+1,b+1+t,cmp);
	for(i=1;i<=t;i++)cout<<b[i];
}
