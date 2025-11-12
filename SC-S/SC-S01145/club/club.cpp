#include<bits/stdc++.h>
using namespace std;
const int eps=-2100000000;
int t,n,ans,te,as,lin;
int f[205][205][205],f2[100005][4],cnta[100005][4],cntb[100005][4],cntc[100005][4];
struct ui{
	int ai;
	int bi;
	int ci;
}num[100005];
inline bool cmp1(ui aaa,ui bbb){
	return aaa.ai>bbb.ai;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int ci=1;ci<=t;ci++){
		cin>>n;
		as=1;
		for(int i=1;i<=n;i++){
			cin>>num[i].ai;
			cin>>num[i].bi;
			cin>>num[i].ci;
			if(num[i].bi!=0||num[i].ci!=0){
				as=0;
			}
		}
		if(n<=200){
			f[1][0][0]=num[1].ci;
			f[1][1][0]=num[1].ai;
			f[1][0][1]=num[1].bi;
			for(int i=2;i<=n;i++){
				for(int a=0;a<=i;a++){
					for(int b=0;b<=i;b++){
						f[i][a][b]=f[i-1][a][b]+num[i].ci;
						if(a-1>=0){
							f[i][a][b]=max(f[i][a][b],f[i-1][a-1][b]+num[i].ai);
						}
						if(b-1>=0){
							f[i][a][b]=max(f[i][a][b],f[i-1][a][b-1]+num[i].bi);
						}
					}
				}
			}
			ans=-1;
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					if(n-i-j<=n/2){
						ans=max(ans,f[n][i][j]);
					}
				}
			}
			cout<<ans<<"\n";
		}
		else{
			if(as){
				sort(num+1,num+1+n,cmp1);
				te=0;
				for(int i=1;i<=n/2;i++){
					te+=num[i].ai;
					te+=num[i].bi;
				}
				cout<<te<<"\n";
			}
			else{
				memset(cnta,0,sizeof(cnta));
				memset(cntb,0,sizeof(cntb));
				memset(cntc,0,sizeof(cntc));
				f2[1][1]=num[1].ai;
				cnta[1][1]=1;
				f2[1][2]=num[1].bi;
				cntb[1][2]=1;
				f2[1][3]=num[1].ci;
				cntc[1][3]=1;
				for(int i=2;i<=n;i++){
					lin=-1;
					for(int j=1;j<=3;j++){
						if(lin<f2[i-1][1]&&cnta[i-1][1]<n/2&&cntb[i-1][1]<=n/2&&cntc[i-1][1]<=n/2){
							lin=f2[i-1][1];
						}
						if(lin<f2[i-1][2]&&cnta[i-1][2]<=n/2&&cntb[i-1][2]<n/2&&cntc[i-1][2]<=n/2){
							lin=f2[i-1][2];
						}
						if(lin<f2[i-1][3]&&cnta[i-1][3]<=n/2&&cntb[i-1][3]<=n/2&&cntc[i-1][3]<n/2){
							lin=f2[i-1][3];
						}
						if(lin==f2[i-1][1])cnta[i][1]=cnta[i-1][1]+1;
						else if(lin==f2[i-1][2])cntb[i][1]=cntb[i-1][1]+1;
						else if(lin==f2[i-1][3])cntc[i][1]=cntc[i-1][1]+1;
						if(lin!=-1){
							if(j==1)f2[i][j]=lin+num[i].ai;
							else if(j==2)f2[i][j]=lin+num[i].bi;
							else if(j==3)f2[i][j]=lin+num[i].ci;
						}
					}
				}
				cout<<max(max(f2[n][1],f2[n][2]),f2[n][3])<<"\n";
			}	
		}
	}
	return 0;
}