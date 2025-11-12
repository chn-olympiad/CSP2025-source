#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T,n,na,nb,nc;
long long sum;
int minn(int x,int y,int z){
	if(x<=y&&x<=z){
		return x;
	}
	else if (y<=x&&y<=z){
		return y;
	}
	else return z;
}
struct node{
	int a,b,c;
	int da,db,dc;
};
node p[maxn],ka[maxn],kb[maxn],kc[maxn];

bool cm(node x,node y){
	return minn(x.da,x.db,x.dc)>minn(y.da,y.db,y.dc);
	
}

void changed(){
	if(na>(n/2)){
		sort(ka+1,ka+na+1,cm);
		for (int i=na;i>(n/2);i--){
			if(ka[i].db<=ka[i].dc){
				sum-=ka[i].db;
				nb++;
				kb[nb]=ka[i];
				kb[i].db=2e4+10,kb[i].da=2e4+10,kb[i].dc=kb[i].b-kb[i].c;
			}
			else{
				sum-=ka[i].dc;
				nc++;
				kc[nc]=ka[i];
				kc[i].dc=2e4+10,kc[i].da=2e4+10,kc[i].dc=kc[i].b-kb[i].c;
			}
		}
		na=n/2;
	}
	else if(nb>(n/2)){
		sort(kb+1,kb+nb+1,cm);
		for (int i=nb;i>(n/2);i--){
			if(kb[i].da<=kb[i].dc){
				sum-=kb[i].da;
				na++;
				ka[na]=kb[i];
				ka[i].da=2e4+10,ka[i].db=2e4+10,ka[i].dc=ka[i].a-ka[i].c;
			}
			else{
				sum-=kb[i].dc;
				nc++;
				kc[nc]=kb[i];
				kc[i].dc=2e4+10,kc[i].db=2e4+10,kc[i].db=kc[i].c-kc[i].b;
			}
		}
		nb=n/2;
	}
	else if(nc>(n/2)){
		sort(kc+1,kc+nc+1,cm);
		for (int i=nc;i>(n/2);i--){
			if(kc[i].da<=kc[i].db){
				sum-=kc[i].da;
				na++;
				ka[na]=kc[i];
				ka[i].dc=2e4+10,ka[i].da=2e4+10,ka[i].db=ka[i].a-kb[i].b;
			}
			else{
				sum-=kc[i].db;
				nb++;
				kb[nb]=kc[i];
				kb[i].db=2e4+10,kb[i].dc=2e4+10,kb[i].da=kb[i].b-kb[i].a;
			}
		}
		nc=n/2;
		
		
	}
	
}

void work(){
	sum=0;
	cin>>n;
	na=0;nb=0;nc=0;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].b>>p[i].c;
		if(p[i].a>=p[i].b&&p[i].a>=p[i].c){
			na++;
			sum+=p[i].a;
			p[i].da=2e4+10,p[i].db=p[i].a-p[i].b,p[i].dc=p[i].a-p[i].c;
			ka[na]=p[i];
		}
		else if(p[i].b>=p[i].a&&p[i].b>=p[i].c) {
			nb++;
			sum+=p[i].b;
			p[i].db=2e4+10,p[i].da=p[i].b-p[i].a,p[i].dc=p[i].b-p[i].c;
			kb[nb]=p[i];
		}
		else {
			nc++;
			sum+=p[i].c;
			p[i].dc=2e4+10,p[i].db=p[i].c-p[i].b,p[i].da=p[i].c-p[i].a;
			kc[nc]=p[i];
		}
	}
	changed();
	changed();

	cout<<sum<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		work();
	}
	
	return 0;
}

