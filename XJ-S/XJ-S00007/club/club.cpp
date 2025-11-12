#include<bits/stdc++.h>
using namespace std;
long long n,t;
long long a[100005][5];
long long d[5][100005],g[5];
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		int w,s;
		for(int i=1;i<=n;i++){
			w=1;
			s=a[i][1];
			for(int h=2;h<=3;h++){
				if(s<a[i][h]){
					s=a[i][h];
					w=h;
				}
			}
			d[w][i]=s;
			g[w]++;
		}
		for(int i=1;i<=3;i++){
			while(g[i]>n/2){
				long long jian=INT_MAX;
				for(int h=1;h<=n;h++){
					if(d[i][h]!=0){
						if(i==1){
							if(jian>a[h][i]-a[h][2]&&a[h][i]-a[h][2]>=0){
								jian=a[h][i]-a[h][2];
								w=h;
								s=2;
							}
							if(jian>a[h][i]-a[h][3]&&a[h][i]-a[h][3]>=0){
								jian=a[h][i]-a[h][3];
								w=h;
								s=3;
							}
						}
						else if(i==2){
							if(jian>a[h][i]-a[h][1]&&a[h][i]-a[h][1]>=0){
								jian=a[h][i]-a[h][1];
								w=h;
								s=1;
							}
							if(jian>a[h][i]-a[h][3]&&a[h][i]-a[h][3]>=0){
								jian=a[h][i]-a[h][3];
								w=h;
								s=3;
							}
						}
						else{
							if(jian>a[h][i]-a[h][1]&&a[h][i]-a[h][1]>=0){
								jian=a[h][i]-a[h][1];
								w=h;
								s=1;
							}
							if(jian>a[h][i]-a[h][2]&&a[h][i]-a[h][2]>=0){
								jian=a[h][i]-a[h][2];
								w=h;
								s=2;
							}
						}
					}
				}
				d[i][w]=0;
				g[s]++;
				d[s][w]=a[w][s];
				g[i]--;
			}
		}
		for(int i=1;i<=3;i++){
			g[i]=0;
			for(int h=1;h<=n;h++){
				if(d[i][h]!=0){
					ans+=d[i][h];
					d[i][h]=0;
				}
				a[h][i]=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
