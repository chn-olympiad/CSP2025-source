#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,q;
struct node{
	string a;
	string b;
}num[400005];
ll a[200005];
bool vis[200005];
bool check(ll x,ll y){
	if(num[x].a.size()>num[y].a.size()) return 0;
	if(num[x].a.size()==num[y].a.size()){
		if(num[x].a==num[y].a&&num[x].b==num[y].b){
			return 1;
		}
		return 0;
	}
	bool f=0;
	for(ll i=0;i<=num[y].a.size()-1;++i){
		if(num[y].a[i]==num[x].a[0]&&i+num[x].a.size()<=num[y].a.size()){
			for(ll j=i;j-i<=num[x].a.size()-1 && j<=i+num[x].a.size()-1;++j){
				if(num[y].a[j]!=num[x].a[j-i] || num[y].b[j]!=num[x].b[j-i]){
					f=1;
					break;
				}
			}
			
			if(f==0){
				
				for(ll j=i+num[x].a.size();j<=num[y].a.size()-1;++j){
					if(num[y].a[j]!=num[y].b[j]){
						return 0;
					}
				}
				return 1;
			}
		}else{
			if(num[y].a[i]!=num[y].b[i]){
				return 0;
			}
		}
	}
	return 0;
}
ll get(string x,string y,ll d){
	ll ans=0;
	for(ll i=1;i<=n;++i){
		if(vis[i]==1){
			vis[a[i]]=1;
			continue;
		}
		if(a[i]<i){
			if(vis[a[i]]==1) vis[i]=1;
		}else{
			if(check(i,n+d)){
				vis[i]=1;
				vis[a[i]]=1;
			}
		}
	}
	for(ll i=1;i<=n;++i){
		if(vis[i]==1){
			ans++;
			vis[i]=0;
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	for(ll i=1;i<=n;++i){
		cin>>num[i].a>>num[i].b;
		a[i]=i;
		for(ll j=1;j<i;++j){
			if(check(i,j)){//i->j
				a[i]=j;
			}
			if(check(j,i)){//j-->i
				a[j]=i;
			}
		}
	}
	for(ll i=1;i<=q;++i){
		cin>>num[n+i].a>>num[n+i].b;
		cout<<get(num[n+i].a,num[n+i].b,i)<<endl;
	}
	return 0;
}
