#include<bits/stdc++.h>
using namespace std;
const int N=10005;
const int M=4000005;
struct road{
	int to,next,val;
}e[M];
int head[N],n,tot,m,k,c[15][N],money_[N],flag[N][N],c_f[15],tot_c;
void build(int x,int y,int d){
	e[++tot].to=y;
	e[tot].val=d;
	e[tot].next=head[x];
	head[x]=tot;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) money_[i]=1e9;
	for(int i=1;i<=m;i++){
		int x,y,d;
		cin>>x>>y>>d;
		build(x,y,d);
		build(y,x,d);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<n;i++){
		int j_=0,l=0;
		for(int j=head[i];j;j=e[j].next){
			if(!flag[i][e[j].to]){
				//cout<<money[i]<<endl;
				if(e[j].val<money_[i]){
					flag[i][j_]=0;
					flag[j_][i]=0;
					flag[i][j]=1;
					flag[j][i]=1;
					j_=j;
					money_[i]=e[j].val;
					//cout<<money_[i]<<' ';
				}
			}
			//cout<<i<<' '<<e[j].to<<' '<<money_[i]<<endl;
		}
		for(int j=1;j<=n;j++){
			if(i!=j){
				for(int z=1;z<=k;z++){
					if(c_f[z]==0){
						if(c[z][i+1]+c[z][1]+c[z][e[j].to+1]<=money_[i]){
							c_f[z]=1;
							money_[i]=c[z][i+1]+c[z][1]+c[z][e[j].to+1];
							//if(l){
								flag[i][j_]=0;
								flag[j_][i]=0;
								flag[i][j]=1;
								flag[j][i]=1;
								j_=j;
						//	}
						}
					}else{
						if(c[z][i+1]+c[z][e[j].to+1]<money_[i] && flag[i][j]){
							money_[i]=c[z][i+1]+c[z][e[j].to+1];
							//cout<<money_[i]<<' ';
						//	if(l){
								flag[i][j_]=0;
								flag[j_][i]=0;
								flag[i][j]=1;
								flag[j][i]=1;
								j_=j;
							//}
						}
					}
				}
			}
		}
	
		
	}
	int ans=0;
	for(int i=1;i<n;i++){
		ans+=money_[i];
		cout<<money_[i]<<endl;
	}
	cout<<ans;
	return 0;
}