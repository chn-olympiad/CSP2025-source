#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5;
int n,cnt[3],T,ans;
priority_queue<int> Q[3];
struct node{
	int x,num;
}b[3];
bool cmp(node p,node q){
	return p.x>q.x;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		for(int i=0;i<3;i++){
			while(Q[i].size())Q[i].pop();
		}
		ans=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				cin>>b[j].x;b[j].num=j;
			}
			sort(b,b+3,cmp);
			ans+=b[0].x;
			cnt[b[0].num]++;
			Q[b[0].num].push(b[1].x-b[0].x);
		}
		for(int i=0;i<3;i++){
			while(cnt[i]>n/2){
				cnt[i]--;
				ans+=Q[i].top();
				Q[i].pop();
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

