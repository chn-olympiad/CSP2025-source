#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e3+30;
ll n,k,a[N],b[N][N];
struct Node{
	ll st,ed;
};
vector<Node>c;
bool cmp(Node a,Node b){
	if(a.ed==b.ed)return a.st>b.st;
	else return a.ed<b.ed;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(j<i)b[i][j]=-1;
			else if(j==i)b[i][j]=a[i];
			else{
				b[i][j]=b[i][j-1]^a[j];
			}
			if(b[i][j]==k){
				c.push_back({i,j});
			}
		}
	}
	sort(c.begin(),c.end(),cmp);
	ll last=-1,ans=0;
	for(ll i=1;i<=n;i++){
		for(int j=0;j<c.size();j++){
			if(c[j].ed==i&&c[j].st>last){
				ans++;
				last=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}