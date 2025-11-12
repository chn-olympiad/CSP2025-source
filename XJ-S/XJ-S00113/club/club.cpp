#include<bits/stdc++.h>
#define N 100005
#define int long long 
using namespace std;

int T,n;
int a[N][3],c[N],ty[N],dl[N]={0},dl1[N]={0};
int ans=0,n1=0,n2=0,n3=0;
struct node{
	int x,val;
}d1[N],d2[N];

bool cmp(node p,node q){
	return p.val>q.val;
}

bool cmp1(int p,int q){
	return p>q;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--){
		memset(dl,0,sizeof(dl));
		for (int i=1;i<=N;++i) ty[i]=1;
		ans=n2=n3=0;
		n1=10;
		cin>>n;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=3;++j){
				cin>>a[i][j];
			}
			c[i]=a[i][1];
			ans+=a[i][1];
			d1[i].val=a[i][2]-a[i][1];
			d1[i].x=i;
		}
	//	cout<<ans<<endl; 
	//	for (int i=1;i<=n;++i) cout<<d1[i].val<<endl;
		sort(d1+1,d1+n+1,cmp);
		for (int i=1;i<=n/2;++i){
			ans+=d1[i].val;
			c[d1[i].x]=a[d1[i].x][2];
			ty[d1[i].x]=2;
			++n2,--n1;
		}
	//	for (int i=1;i<=n;++i) cout<<c[i]<<endl;
	//	cout<<ans<<endl;
		for (int i=1;i<=n;++i){
			d2[i].val=a[i][3]-c[i];
			d2[i].x=i;
		}
	//	for (int i=1;i<=n;++i) cout<<d2[i].val<<endl;
		sort(d2+1,d2+n+1,cmp);
		for (int i=1;i<=n/2;++i){
			if (d2[i].val<=0) break;
			ans+=d2[i].val,++n3;
			if (ty[d2[i].x]==2) --n2;
			else --n1;
			ty[d2[i].x]=3;
		}
		if (n1==5&&n2==5){
			cout<<ans<<endl;
			continue;
		}
		else{
			int cnt=0;
			for (int i=1;i<=n;++i){
				if (ty[i]==1) dl[++cnt]=a[i][2]-a[i][1];
			}
			sort(dl+1,dl+cnt+1,cmp1);
			for (int i=1;i<=(n/2)-n2;++i){
				if (dl[i]<=0) break;
				ans+=dl[i],--n1,++n2;
			}
			cnt=0;
			for (int i=1;i<=n;++i){
				if (ty[i]==2) dl1[++cnt]=a[i][1]-a[i][2];
			}
		//	for (int i=1;i<=cnt;++i) cout<<dl1[i]<<" ";
			sort(dl1+1,dl1+cnt+1,cmp1);
			for (int i=1;i<=(n/2)-n1;++i){
				if (dl1[i]<=0) break;
				ans+=dl1[i],--n2,++n1;
			}
		//	cout<<n1<<" "<<n2<<endl;
		//	for (int i=1;i<=n;++i) cout<<ty[i]<<" ";
			cout<<ans<<"\n";
		}
	}
	return 0;
}
