#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
struct node{
	string s1,s2;
};
node p[N];
int n,q;
void solve(){
	string a,b;
	cin>>a>>b;
	int lena=a.size();
	a='#'+a;
	int ans=0;
	for(int l=1;l<=lena;l++){
		for(int k=1;k<=n;k++){
			string s=p[k].s1;
			int len=s.size();
			int r=l+len-1;
			string c=a.substr(l,r-l+1);
			if(c==s){
				string d=a.substr(1,l-1);
				d+=p[k].s2;
				d+=a.substr(r+1,n-r+1);
				if(d==b) ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i].s1>>p[i].s2;
	for(int i=1;i<=q;i++) solve();
	return 0;
}