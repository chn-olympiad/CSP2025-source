#include<bits/stdc++.h>
using namespace std;
struct node{
	long long w[100010];
}o[4];
long long n,m,t,l[100010],qu[100010],ren[100010][4],si[4],ans,a,kj[100010];
bool cmp(long long aa,long long bb){
	return kj[aa]<kj[bb];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		si[1]=0;si[2]=0;si[3]=0;
		for(int i=1;i<=n;i++){
			l[i]=0;
			qu[i]=0;
			for(int j=1;j<=3;j++){
				ren[i][j]=0;
				o[j].w[i]=0;
			}
		}
		a=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&ren[i][1],&ren[i][2],&ren[i][3]);
			for(int j=1;j<=3;j++){
				if(ren[i][j]>=l[i]){
					qu[i]=j;
					l[i]=ren[i][j];
				}
			}
			ans+=l[i];
		}
		for(int i=1;i<=n;i++){
			o[qu[i]].w[++si[qu[i]]]=i;
		}
		if(si[1]<=n/2&&si[2]<=n/2&&si[3]<=n/2){
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=3;i++){
			if(si[i]>n/2){
				a=i;
				break;
			}
		}
		for(int i=1;i<=si[a];i++){
			long long cc=-1;
			for(int j=1;j<=3;j++){
				if(j!=a){
					cc=max(cc,ren[o[a].w[i]][j]);
				}
			}
			kj[o[a].w[i]]=ren[o[a].w[i]][a]-cc;
		}
		sort(o[a].w+1,o[a].w+1+si[a],cmp);
		m=1;
		while(si[a]>(n/2)){
			long long cc=-1;
			for(int i=1;i<=3;i++){
				if(i!=a){
					cc=max(cc,ren[o[a].w[m]][i]);
				}
			}
			ans-=ren[o[a].w[m]][a]-cc;
			si[a]--;
			m++;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
//rp=pow(114514,1919810)!;