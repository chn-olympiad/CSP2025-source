#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
struct node{
	string s1,s2;
}a[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		ll sum=0;
		for(int i=1;i<=n;i++){
			ll x=a[i].s1.size();
			for(int j=0;j<t1.size()-x+1;j++){
				if(t1.substr(j,x)==a[i].s1){
					string t3=t1;
					t3.replace(j,x,a[i].s2);
					if(t2==t3) sum++;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
