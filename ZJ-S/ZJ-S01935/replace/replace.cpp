#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,Q;
struct E{
	string s,ss;
}a[200010];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;i++) cin>>a[i].s>>a[i].ss;
	while(Q--){
		string s,ss; cin>>s>>ss;
		int lens=s.size(),lenss=ss.size();
		if(lens!=lenss){
			cout<<0<<endl;
			continue;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<lens-a[i].s.size()+1;j++){
				string p="";
				for(int k=j;k<=j+a[i].s.size()-1;k++){
					p=p+s[k];
				}
				if(p==a[i].s){
					p=a[i].ss;
					string h="";
					for(int k=0;k<j;k++){
						h=h+s[k];
					}
					h=h+p;
					for(int k=j+a[i].s.size();k<s.size();k++){
						h=h+s[k];
					}
					if(h==ss){
						sum++;
					}
				}
			}
		}
		cout<<sum<<endl;
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
