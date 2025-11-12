#include<bits/stdc++.h>
#define homo 114514
#define ll long long
using namespace std;
struct ppp{
	int v,id;
}a[homo][4];
int n,cnt[4],T;
ll ans;
bool cmp(ppp x,ppp y){
	return x.v>y.v;
}		
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		priority_queue<int,vector<int>,greater<int> >q[4];
		ans=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1].v,&a[i][2].v,&a[i][3].v);
			a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
		}
		for(int i=1;i<=n;i++){
			sort(a[i]+1,a[i]+3+1,cmp);
			if(cnt[a[i][1].id]<n/2){
				cnt[a[i][1].id]++,ans+=a[i][1].v;
				q[a[i][1].id].push(a[i][1].v-a[i][2].v);
			}
			else{
				int x=a[i][1].v-a[i][2].v;
				if(!q[a[i][1].id].empty()&&q[a[i][1].id].top()<x){
					ans=ans-q[a[i][1].id].top()+a[i][1].v;
//					cout<<i<<" "<<a[i][1].id<<" "<<q[a[i][1].id].top()<<endl;
					q[a[i][1].id].pop();
					q[a[i][1].id].push(x);
				}
				else{
					ans+=a[i][2].v;
				}
			}
//			cout<<ans<<endl;
		}
		cout<<ans<<"\n";
	}	
	return 0;
}