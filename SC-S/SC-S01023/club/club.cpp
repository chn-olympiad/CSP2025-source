#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int T,n,pmax,ans=0,aaa;
int a[100013][3];
int maxn[100013],sum[3],cha[50013];

struct o2{
	int fir,sec,thi;
}o2[50013];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while (T--){
		memset(sum,0,sizeof(sum));
		memset(a,0,sizeof(a));
		memset(maxn,0,sizeof(maxn));
		memset(cha,0,sizeof(cha));
		ans=0;
		cin>>n;
		pmax=n/2;
		for (int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int ki;
			for (int k=0;k<3;k++){
				if (a[i][k]>=maxn[i]){
					maxn[i]=a[i][k];
					ki=k;
				}	
			}
			ans+=a[i][ki];
			sum[ki]++;
			maxn[i]=ki;
		}
		bool i0=1;
		int ki;
		for (int i=0;i<3;i++){
			if (sum[i]>pmax){
				i0=0;
				ki=i;
				aaa=sum[i]-pmax;
				break;
			}
		}
		if (i0) cout<<ans<<'\n';
		else if (!i0){
			int t=0;
			//加入结构体 
			for (int i=1;i<=n;i++){
				if (maxn[i]==ki){
					int kii;
					o2[++t].fir=a[i][ki];
					maxn[i]=0;
					for (int k=0;k<3;k++){
						if (k==ki) continue;
						if (a[i][k]>=maxn[i]){
							maxn[i]=a[i][k];
							kii=k;
						}
					}
					o2[t].sec=a[i][kii];
				}
			}
			//sort
			for (int i=1;i<=t;i++){
				for (int j=i;j<=t;j++){
					if (o2[i].fir>o2[j].fir){
						int x=o2[i].fir,y=o2[i].sec;
						o2[i].fir=o2[j].fir,o2[i].sec=o2[j].sec,
						o2[j].fir=x,o2[j].sec=y;
					}
					if (o2[i].fir==o2[j].fir){
						if (o2[i].sec>o2[j].sec){
							int x=o2[i].fir,y=o2[i].sec;
							o2[i].fir=o2[j].fir,o2[i].sec=o2[j].sec,
							o2[j].fir=x,o2[j].sec=y;
						}
					}
				}
			}
//			for (int i=1;i<=t;i++){
//				cout<<o2[i].fir<<' '<<o2[i].sec<<'\n';
//			}
			// 计算差
			for (int i=1;i<=t;i++)
				cha[i]=o2[i].fir-o2[i].sec;
			sort(cha+1,cha+t+1);
			//容差
//			cout<<aaa<<"aaa"<<ans<<'\n';
			for (int i=1;i<=aaa;i++){
				ans-=cha[i];
			}
//			for (int i=1;i<=t;i++){
//				cout<<o2[i].fir<<' '<<o2[i].sec<<'\n';
//			}
			cout<<ans<<'\n';
		}
	}
	
	
	return 0;
}