#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t;
int a[5][N];
int d[N],w[N];
int v[N],l[N];
int f[3]={0};
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		int s=n/2;
		if(n==2){
			int w,b,c,d,e,f;
			w=a[1][1]+a[2][2];
			b=a[1][1]+a[2][3];
			c=a[1][2]+a[2][1];
			d=a[1][2]+a[2][3];
			e=a[1][3]+a[2][1];
			f=a[1][3]+a[2][2];
			int cnr=max(w,b);
			cnr=max(cnr,c);
			cnr=max(cnr,d);
			cnr=max(cnr,e);
			cnr=max(cnr,f);
			cout<<cnr;
			continue;
		}
		int maxn=-1,flag=-1,cnt=0,minp=-1,mmnn=-1;
		for(int i=1;i<=n;i++){
			maxn=-1,flag=-1;
			for(int j=1;j<=3;j++){
				if(a[i][j]>maxn){
					maxn=a[i][j];
					flag=j;
				}
				if(a[i][j]>minp&&a[i][j]!=maxn){
					minp=a[i][j];
					mmnn=j;
				}
			}
			w[i]=minp;
			l[i]=mmnn;
			if(f[flag]+1>s){
				for(int s=1;s<=n;s++){
					if(cnt-d[s]<cnt-d[s]+maxn&&v[s]==flag||d[s]<maxn&&v[s]==flag){
						cnt-=d[s];
						f[flag]--;
						d[s]=v[s]=0;
					}else if(cnt<cnt-d[s]+w[s]+maxn&&f[l[s]]<=s-1){
						cnt-=d[s];
						f[flag]--;
						d[s]=v[s]=0;
						f[l[s]]++;
						cnt+=w[s];
					}
				}
				cnt+=maxn;
				f[flag]++;
			}else{
				d[i]=maxn;
				v[i]=flag;
				f[flag]++;
				cnt+=maxn;
			}	
		}
		cout<<cnt<<endl;
		f[1]=f[2]=f[3]=0;
		for(int i=1;i<=n;i++){
			v[i]=d[i]=w[i]=l[i]=0;
		}
	}
	return 0;
} 
