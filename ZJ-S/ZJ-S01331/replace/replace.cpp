#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll n,q;
struct node{
	string s1,s2;
}a[N],b;
int main(){
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
	for(int _=1;_<=q;_++){
		cin>>b.s1>>b.s2;
		if(b.s1.size()!=b.s2.size()){cout<<"0\n";continue;}
		ll ans=0;
		for(int i=0;i<b.s1.size();i++){
			for(int j=1;j<=n;j++){
				string t=b.s1;
				bool falg=0;
				if(i+a[j].s1.size()>b.s1.size()) continue;
				for(int k=i;k<i+a[j].s1.size();k++){
					if(t[k]!=a[j].s1[k-i]) falg=1;
					t[k]=a[j].s2[k-i];
				}
				if(t==b.s2 && falg==0) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
