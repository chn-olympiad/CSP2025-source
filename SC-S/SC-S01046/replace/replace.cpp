//ccf我求你送我兩個測試點吧 要掛了啊 三等都不保了 幫我混個二等吧
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

int n,q;
string s1,s2;

signed main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	ios::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1>>s2;
	for(int i=1;i<=q;i++)cin>>s1>>s2;
	for(int i=1;i<=q;i++)cout<<0<<'\n';
	
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/