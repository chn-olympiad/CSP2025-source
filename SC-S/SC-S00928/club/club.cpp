#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N = 1e5+5;
int t,n,ans,sacnt,sbcnt,sccnt,sasum,sbsum,scsum,ta,sa[N],sb[N],sc[N];
struct node{
	int aa,ab,ac,mx,nu;
	int cab,cbc,cac;
}st[N];
bool cmpa1(node a,node b){
	return a.aa>b.aa;
}
void dfs(int x,int sum,int asum,int bsum,int csum){
	if(x==n){
		//cout<<asum<<' '<<bsum<<' '<<csum<<'\n';
		ans=max(ans,sum);
		return ;
	}
	if(asum+1<=n/2){
		dfs(x+1,sum+st[x+1].aa,asum+1,bsum,csum);
	}
	if(bsum+1<=n/2){
		dfs(x+1,sum+st[x+1].ab,asum,bsum+1,csum);
	}
	if(csum+1<=n/2){
		dfs(x+1,sum+st[x+1].ac,asum,bsum,csum+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sacnt=sbcnt=sccnt=sasum=sbsum=scsum=0;
		for(int i=1;i<=n;i++){
			cin>>st[i].aa>>st[i].ab>>st[i].ac;
			if(st[i].ab==0&&st[i].ac==0)
				ta++;
			st[i].mx=max(st[i].aa,max(st[i].ab,st[i].ac));
			if(st[i].aa>st[i].ab&&st[i].aa>st[i].ac){
				sacnt++;
				sasum+=st[i].aa;
				sa[sacnt]=i;
			}
			if(st[i].ab>st[i].aa&&st[i].ab>st[i].ac){
				sbcnt++;
				sbsum+=st[i].ab;
				sb[sbcnt]=i;
			}
			if(st[i].ac>st[i].aa&&st[i].ac>st[i].ab){
				sccnt++;
				scsum+=st[i].ac;
				sc[sccnt]=i;
			}
			st[i].nu=i;
		}
		if(sacnt<=n/2&&sbcnt<=n/2&&sccnt<=n/2){
			cout<<sasum+sbsum+scsum<<'\n';
		}else{
			if(ta==n){
				ll sum=0;
				sort(st+1,st+1+n,cmpa1);
				for(int i=1;i<=n/2;i++){
					sum+=st[i].aa;
				}
				cout<<sum<<'\n';
			}else{
				ans=0;
				dfs(1,st[1].aa,1,0,0);
				dfs(1,st[1].ab,0,1,0);
				dfs(1,st[1].ac,0,0,1);
				cout<<ans<<'\n';
			}
		}
	}
	return 0;
}