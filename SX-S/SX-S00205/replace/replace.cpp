#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200005][6],t1,t2;
int canreplace(int l,int r,int sl){
	int cnt=0;
	string c1=" ",c2=" ",d1=" ",d2=" ";
	for(int i=l;i<=r;i++) c1+=t1[i];
	for(int i=l;i<=r;i++) c2+=t2[i];
	for(int i=1;i<l;i++) d1+=t1[i];
	for(int i=r+1;i<=sl;i++) d1+=t1[i];
	for(int i=1;i<l;i++) d2+=t2[i];
	for(int i=r+1;i<=sl;i++) d2+=t2[i];
	if(d1!=d2) return 0;
	for(int i=1;i<=n;i++){
		if(s[i][1]==c1&&s[i][2]==c2) cnt++;
	}
	return cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		s[i][1]=" "+s[i][1];
		s[i][2]=" "+s[i][2];
	}
	while(q--){
		cin>>t1>>t2;
		unsigned sl=t1.size();
		if(sl!=t2.size()){
			cout<<"0\n";
			continue;
		}ans=0;
		t1=" "+t1;
		t2=" "+t2;
		for(unsigned l=1;l<=sl;l++){
			for(unsigned r=l;r<=sl;r++){
//				printf("%d %d %d\n",l,r,canreplace(l,r,sl));
				ans+=canreplace(l,r,sl);
			}
		}cout<<ans<<endl;
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