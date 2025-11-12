#include<bits/stdc++.h>
using namespace std;
int a[100005][3],p[3],middle[100005],choose[100005];
struct node{
	int id,cha;
	bool operator<(const node s)const{
		return s.cha<cha;
	}
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		for(int i=0;i<3;i++) p[i]=0;
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		priority_queue<node> q1,q2,q3;
		for(int i=1;i<=n;i++){
			int mx=max(a[i][0],max(a[i][1],a[i][2])),mi=min(a[i][0],min(a[i][1],a[i][2]));
			int sum=a[i][0]+a[i][1]+a[i][2];
			if(mx==a[i][0]){
				p[0]++;q1.push({i,mx-(sum-mx-mi)});choose[i]=0;
			}else if(mx==a[i][1]){
				p[1]++;q2.push({i,mx-(sum-mx-mi)});choose[i]=1;
			}else{
				p[2]++;q3.push({i,mx-(sum-mx-mi)});choose[i]=2;
			} 
			int mid=sum-mx-mi;
			if(mid==a[i][0]) middle[i]=0;
			else if(mid==a[i][1]) middle[i]=1;
			else middle[i]=2;
		}
		if(p[0]>n/2){
			while(p[0]>n/2){
				node tp=q1.top();
				p[0]--;
				q1.pop();
				choose[tp.id]=middle[tp.id];
			}
		}else if(p[1]>n/2){
			while(p[1]>n/2){
				node tp=q2.top();
				p[1]--;
				q2.pop();
				choose[tp.id]=middle[tp.id];
			}
		}else{
			while(p[2]>n/2){
				node tp=q3.top();
				p[2]--;
				q3.pop();
				choose[tp.id]=middle[tp.id];
			}	
		}
		int ans=0;
		for(int i=1;i<=n;i++) ans+=a[i][choose[i]];
		cout<<ans<<"\n";
	}
	return 0;
}
