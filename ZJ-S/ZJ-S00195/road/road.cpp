#include <bits/stdc++.h>
using namespace std;
struct grop{
    int a,b,w;
    int value=0;
    bool type=false;
    int town=-1;
};
int city[20040]={-1};
int find(int xxxx){
	if(city[xxxx]==-1) return xxxx;
	int fa= find(city[xxxx]);
	city[xxxx]=fa;
	return fa;
}
void sortf(grop x[] ,  int beg,int end){
    if(end-beg<2) return ;
    if(end-beg==2) {
        if (x[beg].value>x[beg+1].value)swap(x[beg],x[beg+1]);
        return ;
    }
    int l=beg,r=end-1;
    while(l<r){
        while(x[l].value<=x[beg].value&&l<end-1) l++;
        while(x[r].value>=x[beg].value&&r>beg) r--;
        if(l<r) swap(x[l],x[r]);
    }
    swap(x[beg],x[r]);
    sortf(x,r+1,end);
    sortf(x,beg,r);
}
int main(){
	freopen("road.in","r",stdin); freopen("road.out","w",stdin);
	for(int i=0;i<20030;i++) city[i]=-1;
	int n,m,k;
	cin>>n>>m>>k;
	grop r[n+k+5]; int town[k*n+m+105];
	for(int i=0;i<m;i++){
		cin>>r[i].a>>r[i].b>>r[i].w;
		r[i].value=r[i].w;
		r[i].type=true;
	}
	int tot=m;
	for(int i=0;i<k;i++){
		cin>>town[i];
		for(int j=0;j<n;j++){
			cin>>r[tot].w;
			r[tot].a=m+i;
			r[tot].b=j;
			r[tot].value=r[tot].w+town[i];
			r[tot].town=i;
			tot++;
		}
	}
	sortf(r,0,tot);
	int cost=0;
	for(int i=0;i<tot;i++){
		if( find(r[i].a)!=find(r[i].b) ){
			cost+=r[i].w;
			city[r[i].a]=r[i].b;
			if(!r[i].type) for(int j=i;j<tot;j++){
				if(r[j].town==r[i].town){
					r[j].value=r[j].value-town[r[i].town];
				}
			}
			sortf(r,i+1,tot);
		}
	}
	cout<<cost;
	return 0;
}

