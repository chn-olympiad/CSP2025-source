#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=5e5+10;
int n;
ll k,a[maxn],s[maxn];
bool flaga=1,flagb=1,flagc=1;
bool v[maxn];
int l[maxn],r[maxn],cnt; 
bool check(){
	int t[maxn];
	t[0]=0;
	for(int i=1; i<=cnt; i++)
		if(!v[i]) t[l[i]]++,t[r[i]+1]--;
	int u=0;
	for(int i=1; i<=n; i++){
		u+=t[i];
		if(u>1) return false;
	}
	return true;
} 
void dfs(){
	int p=1;
	for(int i=2; i<=cnt; i++){
		if(!v[i]){
			if(l[i]<r[p]){
				if(r[i]>r[p]) v[i]=1;
				else v[p]=1,p=i;
			}
			p=i;
		}
	}
	if(!check()) dfs();
} 
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k!=0) flaga=0;
	if(k>1) flagb=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		if(a[i]!=1) flaga=0;
		if(a[i]>1) flagb=0;
		if(a[i]>255) flagc=0;
	}
	if(flaga){
		cout<<n/2;
		return 0;
	}
	if(flagb){
		if(k==0){
			int ans=0;
			for(int i=1; i<=n; i++){
				if(a[i]==0) ans++;
				if(a[i]==1&&a[i+1]==1) i++,ans++;
			} 
			cout<<ans;
		}
		else if(k==1){
			int ans=0;
			for(int i=1; i<=n; i++)
				if(a[i]==1) ans++;
			cout<<ans;
		}
		return 0;
	}
	map<int,int> q;
	for(int i=1; i<=n; i++)
		if(a[i]==k) q[i]=i;
	for(int L=1; L<=n; L++)
		for(int R=L+1; R<=n; R++){
			int e=s[R]^a[L-1];
			if(e==k){
				q[L]=R;
				break;
			}
		}
	for(auto x:q){
		l[++cnt]=x.first;
		r[cnt]=x.second;
	}
	dfs();
	int ans=0;
	for(int i=1; i<=cnt; i++)
		if(!v[i]) ans++;
	cout<<ans;
	return 0;
}

