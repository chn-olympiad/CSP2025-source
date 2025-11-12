#include<bits/stdc++.h>
using namespace std;\
int t,n;
struct md{
	int cl[3];
	int a;
	int b;
	int c;
}s[100000];
struct xz{
	long long c[10];
	long long sum[10];
}w[100000];
bool pd(md z,md x){
	if(z.cl[z.a]==x.cl[x.a]){
		if(z.cl[z.b]==x.cl[x.b]){
			return z.cl[z.c]>x.cl[x.c];
		}
		return z.cl[z.b]>x.cl[x.b];
	}
	return z.cl[z.a]>x.cl[x.a];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int c[4]={0};
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].cl[0]>>s[i].cl[1]>>s[i].cl[2];
			if(s[i].cl[0]>s[i].cl[1]&&s[i].cl[0]>s[i].cl[2]){
				s[i].a=0;
				if(s[i].cl[1]>s[i].cl[2]){
					s[i].b=1;
					s[i].c=2;
				}else{
					s[i].b=2;
					s[i].c=1;
				}
			}else if(s[i].cl[1]>s[i].cl[0]&&s[i].cl[1]>s[i].cl[2]){
				s[i].a=1;
				if(s[i].cl[0]>s[i].cl[2]){
					s[i].b=0;
					s[i].c=2;
				}else{
					s[i].b=2;
					s[i].c=0;
				}
			}else{
				s[i].a=2;
				if(s[i].cl[0]>s[i].cl[1]){
					s[i].b=0;
					s[i].c=1;
				}else{
					s[i].b=1;
					s[i].c=0;
				}
			}
		}
		sort(s+1,s+1+n,pd);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=3;j++){
				w[i].c[j]=0;
				w[i].sum[j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			int sw[10]={0},h[10],g[10];
			for(int j=1;j<i;j++){
				for(int k=0;k<3;k++){
					if(w[j].c[0]!=(n/2)&&sw[0]<w[j].sum[k]){
						sw[0]=w[j].sum[k];
						h[0]=j;
						g[0]=k;
					}
					if(w[j].c[1]!=(n/2)&&sw[1]<w[j].sum[k]){
						sw[s[i].b]=w[j].sum[k];
						h[1]=j;
						g[1]=k;
					}
					if(w[j].c[2]!=(n/2)&&sw[2]<w[j].sum[k]){
						sw[2]=w[j].sum[k];
						h[2]=j;
						g[2]=k;
					}
				}
			}
			w[i].sum[0]=w[h[0]].sum[g[0]]+s[i].cl[0];
			w[i].c[0]++;
			w[i].sum[1]=w[h[1]].sum[g[1]]+s[i].cl[1];
			w[i].c[1]++;
			w[i].sum[2]=w[h[2]].sum[g[2]]+s[i].cl[2];
			w[i].c[2]++;
//			if(c[s[i].a]==(n/2)){
//				sum+=s[i].cl[s[i].b];
//				c[s[i].b]++;
//			}else{
//				sum+=s[i].cl[s[i].a];
//				c[s[i].a]++;
//			}
//			cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<sum<<endl;
		}
		cout<<max(max(w[n].sum[0],w[n].sum[1]),w[n].sum[2])<<endl;
	}
	return 0;
}
