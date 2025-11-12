#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll t;
struct edge{
	int a,b,c;
};
struct dd{
	int qq,hb,hc;
};
struct gg{
	int qq,ha,hc;
};
struct ff{
	int qq,ha,hb;
};
bool vis[100005];
dd d1[100005],d2[100005];
gg g1[100005],g2[100005];
ff f1[100005],f2[100005];
edge e[100005];
edge x[100005],y[100005],z[100005];
bool cmp1(dd p,dd q){
	return p.hb<q.hb;
}
bool cmp2(dd p,dd q){
	return p.hc<q.hc;
}
bool cmp3(gg p,gg q){
	return p.ha<q.ha;
}
bool cmp4(gg p,gg q){
	return p.hc<q.hc;
}
bool cmp5(ff p,ff q){
	return p.hb<q.hb;
}
bool cmp6(ff p,ff q){
	return p.ha<q.ha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(vis,0,100000); 
		int n,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>e[i].a>>e[i].b>>e[i].c;
		}	
		int s1=0,s2=0,s3=0;
		for(int i=1;i<=n;i++){
			if(e[i].a>e[i].b && e[i].a>e[i].c){
			    s1++;
				x[s1]=e[i];
				sum+=e[i].a;
			}  
			if(e[i].b>e[i].a && e[i].b>e[i].c){
			    s2++;
				y[s2]=e[i];
				sum+=e[i].b;
			}  
			if(e[i].c>e[i].a && e[i].c>e[i].b){
				s3++;
				z[s3]=e[i];
				sum+=e[i].c;
			}  
		}
		int m=n/2;
		if(s1<=m && s2<=m && s3<=m){
			cout<<sum<<endl;
			continue;
		}
		for(int i=1;i<=n;i++) vis[i]=1;
		if(s1>m){
			ll l=s1-m;
			for(int i=1;i<=s1;i++){
				d1[i].hb=abs(x[i].a-x[i].b);
				d1[i].qq=i;
			}
			for(int i=1;i<=s1;i++){
				d2[i].hc=abs(x[i].a-x[i].c);
				d2[i].qq=i;
			}
			sort(d1+1,d1+s1+1,cmp1);
			sort(d2+1,d2+s1+1,cmp2);
			ll ysq1=1,ysq2=1;
			while(1){
			  	if(d1[ysq1].hb<d2[ysq2].hc && vis[d1[ysq1].qq]==1){
			  		sum-=x[d1[ysq1].qq].a;
		        	sum+=x[d1[ysq1].qq].b;
		        	vis[d1[ysq1].qq]=0;
					ysq1++;
		    		l--;
		    	}else if(vis[d2[ysq2].qq]==1){
		    		sum-=x[d1[ysq1].qq].a;
		        	sum+=x[d1[ysq1].qq].c;
		    		vis[d2[ysq2].qq]=0;
		    		l--;
					ysq2++;
		    	}
			    if(l==0) break;
			}
		}
		if(s2>m){
			ll l=s2-m;
			for(int i=1;i<=s2;i++){
				g1[i].ha=abs(y[i].b-y[i].a);
				g1[i].qq=i;
			}
			for(int i=1;i<=s2;i++){
				g2[i].hc=abs(y[i].b-y[i].c);
				g2[i].qq=i;
			}
			sort(g1+1,g1+s2+1,cmp3);
			sort(g2+1,g2+s2+1,cmp4);
			ll ysq1=1,ysq2=1;
			while(1){
			  	if(g1[ysq1].ha<g2[ysq2].hc && vis[g1[ysq1].qq]==1){
			  		sum-=y[g1[ysq1].qq].b;
		        	sum+=y[g1[ysq1].qq].a;
		        	vis[g1[ysq1].qq]=0;
					ysq1++;
		    		l--;
		    	}else if(vis[g2[ysq2].qq]==1){
		    		sum-=x[g1[ysq1].qq].b;
		        	sum+=x[g1[ysq1].qq].c;
		    		vis[g2[ysq2].qq]=0;
		    		l--;
					ysq2++;
		    	}
			    if(l==0) break;
			}
		}
		if(s3>m){
			ll l=s3-m;
			for(int i=1;i<=s3;i++){
				f1[i].hb=abs(z[i].c-z[i].b);
				f1[i].qq=i;
			}
			for(int i=1;i<=s3;i++){
				f2[i].ha=abs(z[i].c-z[i].a);
				f2[i].qq=i;
			}
			sort(f1+1,f1+s3+1,cmp5);
			sort(f2+1,f2+s3+1,cmp6);
			ll ysq1=1,ysq2=1;
			while(1){
			  	if(f1[ysq1].hb<f2[ysq2].ha && vis[f1[ysq1].qq]==1){
			  		sum-=z[f1[ysq1].qq].c;
		        	sum+=z[f1[ysq1].qq].b;
		        	vis[f1[ysq1].qq]=0;
					ysq1++;
		    		l--;
		    	}else if(vis[f2[ysq2].qq]==1){
		    		sum-=z[f1[ysq1].qq].c;
		        	sum+=z[f1[ysq1].qq].a;
		    		vis[f2[ysq2].qq]=0;
		    		l--;
					ysq2++;
		    	}
			    if(l==0) break;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

