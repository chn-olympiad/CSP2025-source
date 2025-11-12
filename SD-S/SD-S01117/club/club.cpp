#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
#define p(i,j) make_pair(i,j)
using namespace std;
const int N=1e5+10;
ll n,m,x,y,z,sum,ans,tmp,cnt,now,u,v,l,r,k,T,ud[5],fA=1,fB=1;//a[N][5];
struct node{
	ll x[5];
}a[N];
struct node2{
	pii x[5];
	node2(node y={0,0,0,0,0}){
		for(int i=1;i<=3;i++) x[i].first=y.x[i],x[i].second=i; 
	}
};
int cmp1(int x,int y){//大到小 
	return x>y;
}
int cmp2(node a,node b){//顺序比较 大到小 
	return a.x[1]==b.x[1]? (a.x[2]==b.x[2]? a.x[3]>b.x[3]:a.x[2]>b.x[2]):a.x[1]>b.x[1];
}
int cmp3(node a,node b){//最大值 大到小 
	ll biga=0,bigai=1;
	for(int i=1;i<=3;i++) if(a.x[i]>biga) biga=a.x[i],bigai=i;
	ll bigb=0,bigbi=1;
	for(int i=1;i<=3;i++) if(b.x[i]>bigb) bigb=b.x[i],bigbi=i;
	if(biga==bigb){
		return bigai>bigbi;
	}else return biga>bigb;
} 
int cmp4(node a,node b){//最大损失值 大到小
	ll biga=0,bigai=1;
	for(int i=1;i<=3;i++) if(a.x[i]>biga) biga=a.x[i],bigai=i;
	ll bigb=0,bigbi=1;
	for(int i=1;i<=3;i++) if(b.x[i]>bigb) bigb=b.x[i],bigbi=i;
	ll smalla=1e9,smallai=1;
	for(int i=1;i<=3;i++) if(a.x[i]<smalla) smalla=a.x[i],smallai=i;
	ll smallb=1e9,smallbi=1;
	for(int i=1;i<=3;i++) if(b.x[i]<smallb) smallb=b.x[i],smallbi=i;
	ll sunshia=biga-smalla,sunshib=bigb-smallb;
//	cout<<biga<<" "<<smalla<<" "<<bigb<<" "<<smallb<<"\n"; 
	if(sunshia==sunshib){
		int seconda=biga-(a.x[0]+a.x[1]+a.x[2]-biga-smalla),secondb=bigb-(b.x[0]+b.x[1]+b.x[2]-bigb-smallb);
		return seconda==secondb? (bigai==bigbi? smallai>smallbi:bigai<bigbi):seconda>secondb;
	}else return sunshia>sunshib;
} 
int cmp5(node a,node b){//B子问题的最大损失值 大到小
	ll biga=max(a.x[1],a.x[2]),bigb=max(b.x[1],b.x[2]),smalla=min(a.x[1],a.x[2]),smallb=min(b.x[1],b.x[2]);
	ll sunshia=biga-smalla,sunshib=bigb-smallb;
	return sunshia>sunshib;
}
void dfs(int x){//分配到了第x个人 
	if(x==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(ud[1]<n/2) ud[1]++,sum+=a[x].x[1],dfs(x+1),sum-=a[x].x[1],ud[1]--;
	if(ud[2]<n/2) ud[2]++,sum+=a[x].x[2],dfs(x+1),sum-=a[x].x[2],ud[2]--;
	if(ud[3]<n/2) ud[3]++,sum+=a[x].x[3],dfs(x+1),sum-=a[x].x[3],ud[3]--;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		fA=fB=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3];
			if(a[i].x[2]!=0) fA=0;
			if(a[i].x[3]!=0) fA=fB=0;
		}
		if(n<=17){
			memset(ud,0,sizeof(ud));
			ans=0;
			sum=0;
			dfs(1);
			cout<<ans<<"\n";
		}else if(fA){
			sort(a+1,a+1+n,cmp2);
			ans=0;
			for(int i=1;i<=n/2;i++) ans+=a[i].x[1];
			cout<<ans<<"\n";
		}else if(fB){
			sort(a+1,a+1+n,cmp5);
			ans=0;
//			for(int i=1;i<=n;i++){
//				ans+=min(a[i].x[1],a[i].x[2]);
//				a[i].x[1]-=min(a[i].x[1],a[i].x[2]);
//				a[i].x[2]-=min(a[i].x[1],a[i].x[2]);
//			}
//			for(int i=1;i<=n/2;i++) ans+=a[i].x[1];
//			for(int i=n/2+1;i<=n;i++) ans+=a[i].x[2];
			ud[1]=ud[2]=0;
			for(int i=1;i<=n;i++){
				if(a[i].x[1]>a[i].x[2]){
					if(ud[1]<n/2) ud[1]++,ans+=a[i].x[1];
					else ud[2]++,ans+=a[i].x[2];
				}else{
					if(ud[2]<n/2) ud[2]++,ans+=a[i].x[2];
					else ud[1]++,ans+=a[i].x[1];
				}
			} 
			cout<<ans<<"\n";
		}else{
			sort(a+1,a+1+n,cmp4);
	//		for(int i=1;i<=n;i++) cout<<a[i].x[1]<<" "<<a[i].x[2]<<" "<<a[i].x[3]<<"\n";
			memset(ud,0,sizeof(ud));
			ans=0;
			for(int i=1;i<=n;i++){
				node2 aa=node2(a[i]);
				sort(aa.x+1,aa.x+4);
				if(ud[aa.x[3].second]<(n/2)) ud[aa.x[3].second]++,ans+=aa.x[3].first;
				else if(ud[aa.x[2].second]<(n/2)) ud[aa.x[2].second]++,ans+=aa.x[2].first;
				else ud[aa.x[1].second]++,ans+=aa.x[1].first;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}

