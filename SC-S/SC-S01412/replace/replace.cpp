#include <bits/stdc++.h>
using namespace std;
const int maxn=200100;
string s[maxn][3],t1,t2;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			int f1=t1.find(s[i][1]),f2=t1.find(s[i][2]),f3=t2.find(s[i][1]),f4=t2.find(s[i][2]),len=t1.length(),siz=s[i][1].size();
			if((f1<INT_MAX || f2<INT_MAX) && ((f1==f4 && t1.substr(0,f1-1)==t2.substr(0,f4-1) && t1.substr(f1+siz,len-1)==t2.substr(f4+siz,len-1)) || (f2==f3 && t1.substr(0,f2-1)==t2.substr(0,f3-1) && t1.substr(f2+siz,len-1)==t2.substr(f3+siz,len-1)))) /*cout<<s[i][1]<<" "<<s[i][2]<<"\n",*/ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/