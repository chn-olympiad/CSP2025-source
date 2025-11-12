#include<bits/stdc++.h>
using namespace std;
int c[11],w1[10005][11];
bool a[10005];
struct sb{
	int u;
	int v;
	int w;
};
bool dsb(sb m1,sb m2){
	return m1.w<m2.w;
}
bool ddsb(sb m1,sb m2){
	return m1.u<m2.u;
}
sb road[50005005];
int main(){
/*	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
long long sum=0,sum1=0;
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>road[i].u>>road[i].v>>road[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
		cin>>w1[j][i];
	}
	for(int i=0;i<=k;i++){
		bool bo=0;
		if(i==0&&m>=n-1){
		sort(road,road+m,dsb);
		int te=0;
		for(int j=1;j<=m;j++){
			if((a[road[j].u]!=1)||(a[road[j].v]!=1))
			sum+=road[j].w;
			a[road[j].u]=1;
			a[road[j].v]=1;
			te++;
			if(te==n-1){
				bo=1;
				break;
			}
	        }
	    }
	    if(bo){
	    for(int j=1;j<=n;j++) a[j]=0;
	    continue;	
		}
	    sum1+=c[i];
	    for(int j=1;j<=n;j++)
		for(int p=1;p<=n;p++)
		for(int q=1;q<=n;q++)
		if(q!=p){				    
	    	road[m+1].u=p;
	    	road[m+1].v=q;
	    	road[m+1].w=w1[p][i]+w1[q][i];
	    	sort(road,road+m,ddsb);
	    	int r=m;
	    	bool www=0;
	    	for(int l=1;l<=m;l++)
	    	if(road[m+1].u==road[l].u&&road[m+1].v==road[l].v){
	    		www=1;
	    		r=l;
	    		break;
			}
			if(www){
				if(road[m+1].w<road[r].w)
					road[r].w=road[m+1].w;
					else m++;
			}
				
			 else m++;
	}
	sort(road,road+m,dsb);
		int te=0;
		if(m>=n-1)
		for(int j=1;j<=m;j++){
			if((a[road[j].u]!=1)||(a[road[j].v]!=1))
			sum+=road[j].w;
			a[road[j].u]=1;
			a[road[j].v]=1;
			te++;
			if(te==n-1){
				sum=min(sum,sum1);
				sum1=c[i];
				break;
			}
	        }
	    for(int j=1;j<=n;j++) a[j]=0;
}
cout<<sum;
	return 0;
}
