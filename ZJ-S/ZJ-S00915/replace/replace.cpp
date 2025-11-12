#include<bits/stdc++.h>
#define For(i,l,r) for(int i=(l);i<=(r);++i)
using namespace std;
const int N=2e5+10;
int n,q,d[N];
string s1[N],s2;
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	For(i,1,n){
		cin>>s1[i]>>s2;
		int d1=s1[i].find('b'),d2=s2.find('b');
		d[i]=d2-d1;
	} 
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		int d1=t1.find('b'),d2=t2.find('b');
		int dd=d2-d1;
		For(i,1,n) if(dd==d[i]&&t1.find(s1[i])!=-1) ++ans;
		cout<<ans<<"\n";
	}
	return 0;
}

