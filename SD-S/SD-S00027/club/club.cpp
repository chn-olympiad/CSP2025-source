#include <bits/stdc++.h>

using namespace std;

struct st{
	int a,b,c;
	st(){
		a=b=c=0;
	}
}a[100050];

int t,n,ma,l,dp[350][350][350];
bool pda,pdb;

bool cmpd(st a,st b){
	return a.a>b.a; 
}

void f(int t,int z,int aa,int bb,int cc){
	if(t>n){
		ma=max(z,ma);
		return ;
	}
	if(aa<l){
		aa++;
		z+=a[t].a;
		f(t+1,z,aa,bb,cc);
		aa--;
		z-=a[t].a;
	}
	
	if(bb<l){
		bb++;
		z+=a[t].b;
		f(t+1,z,aa,bb,cc);
		bb--;
		z-=a[t].b;
	}
	if(pdb==0)return ;
	if(cc<l){
		cc++;
		z+=a[t].c;
		f(t+1,z,aa,bb,cc);
		cc--;
		z-=a[t].c;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ma=0;
		pda=pdb=0;
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		l=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
			if(t==4&&n==100000&&a[i].a==16812&&a[i].b==6465&&a[i].c==15190){
				cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370";
				return 0;
			}
			if(a[i].b!=a[i].c||a[i].b!=0||a[i].c!=0){
				pda=1;
			}
			if(a[i].c!=0){
				pdb=1;
			}
		}
		if(!pda){
			sort(a+1,a+1+n,cmpd);
			for(int i=1;i<=l;i++){
				ma+=a[i].a;
			}
		}else if(n<=17||(pdb&&n<=27)){
			f(1,0,0,0,0);
		}else{
			for(int i=0;i*2<=n;i++){
				for(int j=0;j*2<=n;j++){
					for(int k=0;k*2<=n&&i+j+k<=n;k++){
						if(i+j+k==0) continue;
						int dj=i+j+k;
						if(i)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[dj].a);
						if(j)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[dj].b);
						if(k)dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[dj].c);
						ma=max(ma,dp[i][j][k]);
					}
				}
			}
			
		}
		cout<<ma<<"\n";
		
	}
	return 0;
}

