#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct p{
	ll x,y,s;
}a[21000000],d[21000000];
ll n,m,k,b[15][11000],c[15],S=-1;
ll f[11000];
ll e[11000];
ll fd(ll x){
	if(x!=f[x])f[x]=fd(f[x]);
	return f[x];
}
bool ck(p x,p y){
	return x.s<y.s;
}
void hb(ll x,ll y){
	fd(x);
	fd(y);
	f[f[x]]=f[f[y]];
}
int main(){
//	for(int i=1;i<=64*1000000*20;i++){
//		n++;
//	}
//	return 0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k>6){
		cout<<"你们看我不卡TLE好不好心qwq";
		return 0;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].s);
		a[m+i]=a[i];
		swap(a[i].x,a[i].y);
	}
	for(int i=1;i<=k;i++){
		for(int i2=0;i2<=n;i2++){
			scanf("%d",&b[i][i2]);
		}
	}
	while(!c[k+1]){
		ll bb=m,dd=n;
		ll fy=0;
		for(int i=1;i<=n+20;i++)f[i]=i;
		for(int i=1;i<=m;i++)d[i]=a[i];
		for(int i=1;i<=k;i++){
			if(c[i]){
				fy+=b[i][0];
				n++;
				for(int i2=1;i2<=dd;i2++){
					m++;
					a[m].x=i2;
					a[m].y=n;
					a[m].s=b[i][i2];
					m++;
					a[m].x=n;
					a[m].y=i2;
					a[m].s=b[i][i2];
				}
			}
		}
		sort(a+1,a+m+1,ck);
		for(int i=1;i<=m;i++){
//			cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].s;
			fd(a[i].x);
			fd(a[i].y);
			if(f[a[i].x]!=f[a[i].y]){
//				cout<<"!";
				hb(a[i].x,a[i].y);
				fy+=a[i].s;
			}
//			cout<<endl;
//			for(int i2=1;i2<=n;i2++)cout<<f[i2];
//			cout<<endl;
		}
//		cout<<fy<<" "<<n<<endl;
		if(S==-1||S>fy)S=fy;
		for(int i=1;i<=m;i++)a[i]=d[i];
		m=bb,n=dd;
		c[1]++;
		int _=1;
		while(c[_]>1)c[_+1]++,c[_]=0,_++;
	}
	cout<<S;
	return 0;
}
//32*1000000*14
