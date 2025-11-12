#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n;
struct node{
	int zimu,bianhao,shu;
};
node p[100005];
bool cmp(node x,node y){
	return x.shu>y.shu;
}
bool vis[100005];
int pl[100005];
int mkl=0;
int aaa[3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		/*
		if(n==10){
			int mmm=0;
			int ppp[11][4];
			for(int i=1;i<=n;i++){
				cin>>ppp[i][1]>>ppp[i][2]>>ppp[i][3];
			}
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for()
				}
			}
		}
		*/
		if(n==4){
			int mmm=0;
			int ppp[5][4];
			for(int i=1;i<=n;i++){
				cin>>ppp[i][1]>>ppp[i][2]>>ppp[i][3];
			}
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int z=1;z<=3;z++){
						for(int kkk=1;kkk<=3;kkk++){
							if((i==j&&j==z)||(i==z&&z==kkk)||(j==z&&z==kkk)||(i==j&&j==kkk)||(i==j&&j==kkk&&kkk==z)){
								continue;
							}
						//	cout<<ppp[1][i]<<" "<<ppp[2][j]<<" "<<ppp[3][z]<<" "<<ppp[4][kkk]<<endl;
						//	cout<<i<<" "<<j<<" "<<z<<" "<<kkk<<endl;
							mmm=max(mmm,ppp[1][i]+ppp[2][j]+ppp[3][z]+ppp[4][kkk]);
						} 
					}
				}
			}
			cout<<mmm<<endl;
			continue;
		}
		int nn=n/2;
		int h=1,ll=0,lklklk=0;
		for(int i=1;i<=n*3;i+=3){
			cin>>p[i].shu;
			p[i].bianhao=h;
			p[i].zimu=0;
			cin>>p[i+1].shu;
			p[i+1].bianhao=h;
			p[i+1].zimu=1;
			cin>>p[i+2].shu;
			p[i+2].bianhao=h;
			p[i+2].zimu=2;
			lklklk=lklklk+(p[i].shu+p[i+1].shu+p[i+2].shu);
			if(p[i+1].shu==p[i+2].shu&&p[i+2].shu==0&&p[i+1].shu==0){
				ll++;
				pl[h]=p[i].shu;
			}
			h++;
		}
		if(ll==n){
			sort(pl+1,pl+h+1);
			int uuu=0;
			int kkkkkk=0;
			for(int i=h;i>=(n/2)+1;i--){
				uuu+=pl[i];
			}
			cout<<uuu<<endl;
			continue;
		}
		if(n==2){
			int mmm=0;
			for(int i=1;i<=3;i++){
				for(int j=4;j<=6;j++){
					if(i==j-3){
						continue;
					}
					mmm=max(mmm,p[i].shu+p[j].shu);
				}
			}
			cout<<mmm<<endl;
			continue;
		}
		int sum=0;
		sort(p+1,p+3*n+1,cmp);
		for(int i=1;i<=n*3;i++){
			if(vis[p[i].bianhao]==0&&aaa[p[i].zimu]+1<=nn){
				sum+=p[i].shu;
			//	cout<<sum<<" "<<p[i].bianhao<<" "<<p[i].zimu<<" "<<p[i].shu<<endl;
				vis[p[i].bianhao]=1;
				aaa[p[i].zimu]++;
			}
		}
		cout<<sum<<endl;
		memset(vis,0,sizeof(vis));
		memset(p,0,sizeof(p));
		aaa[0]=aaa[1]=aaa[2]=0;
	} 
	return 0;
}
