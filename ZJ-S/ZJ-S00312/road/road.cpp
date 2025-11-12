#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k,f[1010],s,ww[11],use[11],sum=LLONG_MAX,num,h[11],wei[11],ed;

struct node{
	int i,j;
	int w;
}a[1020000];

struct node1{
	int ii;
	int w;
}cz[11][1010];

bool cmp(node x1,node y1){
	return x1.w<y1.w;
}

bool cmp1(node1 x1,node1 y1){
	return x1.w<y1.w;
}

int fa(int x){
//	return f[x]==x ? x : f[x]=fa(f[x]);
	if(f[x]==x) return x;
	else{
		f[x]=fa(f[x]);
		return f[x];
	}
}

void sou(){
	int minn,mini;
	for(int i=1;i<=n;i++) f[i]=i;
	s=0,ed=1;
	for(int kk=1;kk<=n-1;kk++){
		while(fa(a[ed].i)==fa(a[ed].j)) ed++;
		minn=a[ed].w,mini=0;
		for(int i=1;i<=k;i++){
			if(use[i]==0) continue;
			while(fa(cz[i][1].ii)==fa(cz[i][wei[i]].ii)) {
				wei[i]++;
//				if(wei[i]<=n) cout<<i<<"      "<<wei[i]<<'\n';

			}
			if(h[i]==0) {
				if(minn>=cz[i][1].w+cz[i][wei[i]].w){
					minn=cz[i][1].w+cz[i][wei[i]].w,mini=i;
				}
			}
			else{
				if(minn>=cz[i][wei[i]].w){
					minn=cz[i][wei[i]].w,mini=i;
				}
			}
		}
		if(mini==0) {
//			cout<<0<<' '<<a[ed].i<<' '<<a[ed].j<<'\n';
			f[fa(f[a[ed].i])]=a[ed].j;
			num+=a[ed].w;
			ed++;
//			cout<<ed<<" "<<num<<'\n';
		}
		else{
//			cout<<mini<<' '<<cz[mini][wei[mini]].ii<<' '<<cz[mini][1].ii<<'\n';
			if(h[mini]==0) num+=cz[mini][1].w;
			h[mini]=1;
			num+=cz[mini][wei[mini]].w;
			f[fa(f[cz[mini][wei[mini]].ii])]=cz[mini][1].ii;
			wei[mini]++;
		}
	}//for(int kkk=1;kkk<=n;kkk++) cout<<fa(kkk)<<" ";
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
//	ios::std::sync_with_stdio();cin.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&a[i].i,&a[i].j,&a[i].w);
	}
	
	sort(a+1,a+1+m,cmp);
	
	for(int i=1;i<=k;i++){
		cin>>ww[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&cz[i][j].w);
			cz[i][j].ii=j;
		}
		sort(cz[i]+1,cz[i]+1+n,cmp1);
	}
	
	for(int i1=0;i1<(1<<k);i1++){
//		cout<<i1<<'\n';
		int ii=i1,t=1;
		num=0;
		for(int j=1;j<=k;j++) use[j]=0,h[j]=0,wei[j]=1;
		while(ii){
			if(ii%2==1) use[t]=1,num+=ww[t];
			t++;
			ii/=2;
		}
		sou();
		sum=min(sum,num);
		
//		cout<<'\n';
//		cout<<i1<<' '<<num<<'\n';
	}
	cout<<sum<<'\n';
}
