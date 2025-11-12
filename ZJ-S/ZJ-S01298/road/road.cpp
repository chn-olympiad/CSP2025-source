#include<bits/stdc++.h>
using namespace std;
long long i,n,new_n,m,lb,nlb,x,fafx,fafy,new_m,j,xx,yy,fx,fy,fz,fa[1000010],k,t,s,mi,chan[110],js[110],xl[12][10010];
struct node{
	int x;
	int y;
	int z;
};
node new_f[101010],f[1000010];
bool cmp(node t,node w){
	return t.z<w.z;
}
int fnd(int x){
	if(fa[x]-x)
		return fa[x]=fnd(fa[x]);
	return x;
}
void init(int x){
	int i,lb,nlb,xx;
	xx=x;
	s=0;
	while(x){
		lb=x&(-x);
		chan[lb]=++new_n;
		nlb=__lg(lb)+1;
		s=s+js[nlb];
//		cout<<nlb;
		for(i=1;i<=n;i++){
			new_f[++new_m].x=chan[lb];
			new_f[new_m].y=i;
			new_f[new_m].z=xl[nlb][i];
//			cout<<new_m<<" "<<chan[lb]<<" "<<i<<" "<<xl[nlb][i]<<endl;
		}
		x=x-lb;
	}
	sort(new_f+1,new_f+1+new_m,cmp);
//	for(i=1;i<=new_m;i++)
//		cout<<new_f[i].x<<" "<<new_f[i].y<<" "<<new_f[i].z<<endl;
	for(i=1;i<=n+k;i++)
		fa[i]=i;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=m;++i)
		cin>>f[i].x>>f[i].y>>f[i].z;
//		scanf("%lld%lld%lld",&f[i].x,&f[i].y,&f[i].z);
	sort(f+1,f+1+m,cmp);
//	for(i=1;i<=m;i++)
//		cout<<f[i].x<<" "<<f[i].y<<" "<<f[i].z<<endl;
//	cout<<endl;
	for(i=1;i<=k;++i){
		cin>>js[i];
		for(j=1;j<=n;++j)
			cin>>xl[i][j];
	}
	mi=2e18;
	for(t=0;t<(1<<k);t++){	
		new_n=n;
		new_m=0;
		xx=1;
		yy=1;
		i=1;
		init(t);
		while(i<new_n){
			if(xx>new_m||new_f[xx].z>=f[yy].z&&yy<=m){
				fx=f[yy].x;
				fy=f[yy].y;
				fz=f[yy].z;
				yy++;
			}
			else{
				fx=new_f[xx].x;
				fy=new_f[xx].y;
				fz=new_f[xx].z;
				xx++;
			}
			fafx=fnd(fx);
			fafy=fnd(fy);
//			if(t==3){
//				cout<<t<<" "<<new_m<<" "<<new_n<<" "<<i<<" "<<xx<<" "<<yy<<" "<<fx<<" "<<fy<<" "<<fz<<" "<<fafx<<" "<<fafy<<endl;
//				Sleep(500);
//			}
			if(fafx-fafy){
				fa[fafx]=fafy;
				s=s+fz;
				if(s>=mi)
					i=2e9;
				i++;
			}
		}
//		cout<<t<<" "<<s<<endl;
		mi=min(mi,s);
	}
	cout<<mi;
}
