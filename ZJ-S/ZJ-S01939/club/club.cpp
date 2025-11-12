#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005][5],b[5],c[5][100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		b[1]=b[2]=b[3]=0;
		memset(c,0,sizeof(c));
		cin>>n;
		int cnt=0;
		int f=0,g=0,h=0;
		for(int i=1;i<=n;i++){
			int maxn=-1;
			int maxx=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>maxn){
					maxn=a[i][j];
					maxx=j;
				}
			}
			sort(a[i]+1,a[i]+4);
			if(maxx==1){
				f++;
				c[1][f]=maxn-a[i][2];
			}
			if(maxx==2){
				g++;
				c[2][g]=maxn-a[i][2];
			}
			if(maxx==3){
				h++;
				c[3][h]=maxn-a[i][2];
			}
			b[maxx]++;
			cnt+=maxn;
		}
		sort(c[1]+1,c[1]+f+1);
		sort(c[2]+1,c[2]+g+1);
		sort(c[3]+1,c[3]+h+1);
		for(int i=1;i<=3;i++){
			if(b[i]>(n/2)){
				int lll=0;
				while(b[i]>(n/2)){
					lll++;
					cnt-=c[i][lll];
					b[i]--;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
