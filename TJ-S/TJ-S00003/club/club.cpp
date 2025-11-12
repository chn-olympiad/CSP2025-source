#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int t;
int n;
int x[N],y[N],z[N];
int maa,mab,mac;
bool f[N];

bool cmp(int a,int b){
	return a>b;
}

bool mao(int w,int v){
	int m;
	if(x[v]>=y[v]&&x[v]>=z[v]) m=x[v];
	if(y[v]>=x[v]&&y[v]>=z[v]) m=y[v];
	if(z[v]>=x[v]&&z[v]>=y[v]) m=z[v];
	
	return m==w;
}
int ma;
int cnta,cntb,cntc;
int opa,opb,opc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ma=0;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];
			f[i]=false;	
		}
		
		if(y[1]==0&&z[1]==0){
			sort(x+1,x+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ma+=x[i];
			}
			cout<<ma<<endl;
			continue;
		}
		
		if(z[1]==0){
			for(int i=1;i<=n;i++){
				ma+=max(x[i],y[i]);
			}
			cout<<ma<<endl;
			continue;
		}
		for(int j=1;j<=n/3+1;j++){
			maa=0;mab=0;mac=0;
			cnta=0;cntb=0;cntc=0;
			opa=0;opb=0;opc=0;
			for(int i=1;i<=n;i++){
				if(maa<=x[i]&&!f[i]&&mao(x[i],i)&&opa<=n/2){
					if(cnta!=0) f[cnta]=false;
					f[i]=true;
					maa=x[i];
					cnta=i;
					opa++;
				}
				if(mab<=y[i]&&!f[i]&&mao(y[i],i)&&opb<=n/2){
					if(cntb!=0) f[cntb]=false;
					f[i]=true;
					mab=y[i];
					cntb=i;
					opb++;
				}
				if(mac<=z[i]&&!f[i]&&mao(z[i],i)&&opc<=n/2){
					if(cntc!=0) f[cntc]=false;
					f[i]=true;
					mac=z[i];
					cntc=i;
					opc++;
				}
			}
			ma+=(maa+mab+mac);
		}
		
		cout<<ma<<endl;	
	}
	return 0;
} 
