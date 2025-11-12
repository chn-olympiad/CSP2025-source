#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;

const int N=1e5+10;

int T,n;

int a[N][3],fs[N],vis[N];

struct Node{
	int num,val;
}b[N<<1];

ll ans=0;

bool cmp(Node x,Node y){
	return x.val>y.val;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>T;
	
	while(T--){
		cin>>n;
		ans=0;
		ll cnt0=0,cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				ans+=a[i][0];
				fs[i]=0;
			}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				ans+=a[i][1];
				fs[i]=1;
			}else{
				ans+=a[i][2];
				fs[i]=2;
			}
			if(fs[i]==0) cnt0++;
			if(fs[i]==1) cnt1++;
			if(fs[i]==2) cnt2++;
			vis[i]=0;
		}
		if(cnt0>n/2){
			int cc=0;
			for(int i=1;i<=n;i++){
				if(fs[i]==0){
					b[++cc]={i,a[i][1]-a[i][0]};
					b[++cc]={i,a[i][2]-a[i][0]};
				}
			}
			sort(b+1,b+cc+1,cmp);
			int cnt=0;
			for(int i=1;i<=cc;i++){
				if(cnt==cnt0-(n/2)){
					break;
				}
				if(!vis[b[i].num]){
					vis[b[i].num]=1;
					ans+=b[i].val;
					cnt++;
				}
			}
			cout<<ans<<"\n";
		}else if(cnt1>n/2){
			int cc=0;
			for(int i=1;i<=n;i++){
				if(fs[i]==1){
					b[++cc]={i,a[i][0]-a[i][1]};
					b[++cc]={i,a[i][2]-a[i][1]};
				}
			}
			sort(b+1,b+cc+1,cmp);
			int cnt=0;
			for(int i=1;i<=cc;i++){
				if(cnt==cnt1-(n/2)){
					break;
				}
				if(!vis[b[i].num]){
					vis[b[i].num]=1;
					ans+=b[i].val;
					cnt++;
				}
			}
			cout<<ans<<"\n";
		}else if(cnt2>n/2){
			int cc=0;
			for(int i=1;i<=n;i++){
				if(fs[i]==2){
					b[++cc]={i,a[i][1]-a[i][2]};
					b[++cc]={i,a[i][0]-a[i][2]};
				}
			}
			sort(b+1,b+cc+1,cmp);
			int cnt=0;
			for(int i=1;i<=cc;i++){
				if(cnt==cnt2-(n/2)){
					break;
				}
				if(!vis[b[i].num]){
					vis[b[i].num]=1;
					ans+=b[i].val;
					cnt++;
				}
			}
			cout<<ans<<"\n";
		}else{
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
