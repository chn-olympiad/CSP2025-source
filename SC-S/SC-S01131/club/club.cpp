#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int t,n;
struct node{
	int val,pos;
} cnt[5],sum[N];
int a[N][5],maxn[N],ans;
bool flag;
vector<int> G[5];
bool cmp(node x,node y){
	return x.val>y.val;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		ans=0;
		memset(maxn,0,sizeof(maxn));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=3;i++){
			cnt[i].pos=i;G[i].clear();
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];maxn[i]=max(maxn[i],a[i][j]);
			}ans+=maxn[i];flag=false;
			for(int j=1;j<=3;j++){
				if(maxn[i]==a[i][j] && flag==false){
					G[j].push_back(i);
					cnt[j].val++;flag=true;
				}
			}
		}
		sort(cnt+1,cnt+4,cmp);
		if(cnt[1].val<=n/2){
			cout<<ans<<'\n';
			continue;
		}
		else{
			int tot=0,p;
			for(auto i:G[cnt[1].pos]){
				tot++;
				for(int j=1;j<=3;j++){
					if(maxn[i]==a[i][j]){
						p=j;break;
					}
				}
				sum[tot].val=(p==1?a[i][2]-maxn[i]:a[i][1]-maxn[i]);
				sum[tot].pos=(p!=3?a[i][3]-maxn[i]:a[i][2]-maxn[i]);
				if(sum[tot].val<sum[tot].pos){
					swap(sum[tot].val,sum[tot].pos);
				}
			}
			sort(sum+1,sum+tot+1,cmp);
			for(int i=1;i<=tot-n/2;i++){
				ans+=sum[i].val;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
