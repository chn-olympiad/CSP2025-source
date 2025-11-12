#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a[200005][5],fin,sen,thn,finum,senum,thnum;
ll ans=0;
struct node{
	int num,val;
}fi[200005],se[200005],th[200005];
bool cmp(node x,node y){
	return x.val>y.val;
}
void dfs(int x,ll sum,int f,int s,int t){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	if(f<n/2) dfs(x+1,sum+a[x][1],f+1,s,t);
	if(s<n/2) dfs(x+1,sum+a[x][2],f,s+1,t);
	if(t<n/2) dfs(x+1,sum+a[x][3],f,s,t+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		memset(a,0,sizeof(a));
		memset(fi,0,sizeof(fi));
		memset(se,0,sizeof(se));
		memset(th,0,sizeof(th));
		fin=sen=thn=finum=senum=thnum=0;
		scanf("%d",&n);
		if(n<=30){
			for(int i=1;i<=n;i++){
				cin >> a[i][1] >> a[i][2] >> a[i][3];
			}
			dfs(1,0,0,0,0);
			cout << ans << endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				fi[++fin].val=a[i][1];
				fi[fin].num=i;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				se[++sen].val=a[i][2];
				se[sen].num=i;
			}else{
				th[++thn].val=a[i][3];
				th[thn].num=i;
			}
		}
		sort(fi+1,fi+1+fin,cmp);
		sort(se+1,se+1+sen,cmp);
		sort(th+1,th+1+thn,cmp);
		if(fin>n/2){
			for(int i=1;i<=fin;i++){
				if(finum<n/2){
					
					ans+=fi[i].val;
					finum++;
				}else{
					int num=fi[i].num;
					if(a[num][2]>a[num][3]){
						se[++sen].val=a[num][2];
					}else th[++thn].val=a[num][3];
				}
			}
			
			for(int i=1;i<=sen;i++){
				ans+=se[i].val;
			}
			for(int i=1;i<=thn;i++){
				ans+=th[i].val;
			}
		}else if(sen>n/2){
			for(int i=1;i<=sen;i++){
				if(senum<n/2){
					
					ans+=se[i].val;
					senum++;
				}else{
					int num=se[i].num;
					if(a[num][1]>a[num][3]){
						fi[++fin].val=a[num][1];
					}else th[++thn].val=a[num][3];
				}
			}
			
			for(int i=1;i<=fin;i++){
				ans+=fi[i].val;
			}
			for(int i=1;i<=thn;i++){
				ans+=th[i].val;
			}
		}else{
			for(int i=1;i<=thn;i++){
				if(thnum<n/2){
					
					ans+=th[i].val;
					thnum++;
				}else{
					int num=th[i].num;
					if(a[num][2]>a[num][1]){
						se[++sen].val=a[num][2];
					}else fi[++fin].val=a[num][1];
				}
			}
			
			for(int i=1;i<=sen;i++){
				ans+=se[i].val;
			}
			for(int i=1;i<=fin;i++){
				ans+=fi[i].val;
			}
		}
			
		printf("%lld\n",ans);
	}
	return 0;
}
