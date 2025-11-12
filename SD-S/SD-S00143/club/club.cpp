#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
struct node{
	int num,k,d;
}a[N];
bool cmp(node A,node B){
	return A.num>B.num; 
}
int t;
int n;
int tot;
int v[N];
int cnt[N];
int ans; 
void solve(){
	cin>>n;
	ans=0;
	memset(a,0,sizeof a);
	memset(cnt,0,sizeof cnt);
	memset(v,0,sizeof v);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
		 	int x;
		 	cin>>x;
		 	a[++tot]={x,i,j};
		}
	}
	sort(a+1,a+1+tot,cmp);	
	for(int i=1;i<=n;i++){
		int x=a[i].num,y=a[i].k,z=a[i].d;
		if(v[y]){
			continue;
		}
		if(cnt[z]==n/2){
			continue;
		}
		ans+=x;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
		solve();	
	return 0;
}

