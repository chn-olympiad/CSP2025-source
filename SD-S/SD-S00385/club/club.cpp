#include<bits/stdc++.h>
using namespace std;
int a[100010][5],b[100010][4],e[100010],c[100010][4],d[100010];
int si[4],s1[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int s;
		cin>>s;
		for(int j=1;j<=s;j++){
			for(int k=1;k<=3;k++){
				b[j][k]=-1;
				c[j][k]=-1;
			}
		}
		for(int j=1;j<=s;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			int a1=max(a[j][1],max(a[j][2],a[j][3]));
			int b1=min(a[j][1],min(a[j][2],a[j][3]));
			int c1=a[j][1]+a[j][2]+a[j][3]-a1-b1;
			for(int k=1;k<=3;k++){
				if(a[j][k]==a1){
					b[j][k]=a1;
					break;
				}
			}
			for(int k=1;k<=3;k++){
				if(a[j][k]==c1){
					c[j][k]=c1;
					break;
				}
			}
		}
		for(int j=1;j<=s;j++){
			for(int k=1;k<=3;k++){
				if(b[j][k]>=0){
					si[k]++;
				}
			}
		}
		for(int j=1;j<=3;j++){
			if(si[j]>s/2){
				while(si[j]>s/2){
				int minn=1000000;
				for(int k=1;k<=s;k++){
					if(b[k][j]>=0){	
					minn=min(minn,b[k][j]);
					}
				}int sum=0;
				for(int k=1;k<=s;k++){
					if(b[k][j]==minn){
						sum++;
						d[sum]=k;
						e[sum]=j;
					}
				}
				int maxx=-1;
				for(int k=1;k<=sum;k++){
					for(int q=1;q<=s;q++){
						for(int f=1;f<=3;f++){
							if(b[q][f]>=0&&b[q][f]!=minn){
								int cnt=0;
								for(int w=1;w<=3;w++){
									if(c[q][w]>=0){
										cnt=c[q][w];
										break;
									}
								}
								if(cnt+b[d[k]][e[k]]>=b[q][f]){
									maxx=max(maxx,cnt+b[d[k]][e[k]]);
								}
								else{
									b[d[k]][e[k]]=c[d[k]][e[k]];
								}
							}
						}
					}
				}
				for(int k=1;k<=sum;k++){
					for(int q=1;q<=s;q++){
						for(int f=1;f<=3;f++){
							if(b[q][f]>=0&&b[q][f]!=minn){
								int cnt=0;
								for(int w=1;w<=3;w++){
									if(c[q][w]>=0){
										cnt=c[q][w];
										break;
									}
								}
								if(cnt+b[d[k]][e[k]]==maxx){
									si[j]--;
									b[q][f]=cnt;
								}
							}
						}
					}
				}
			}
			}
		}
		int ans=0;
		for(int j=1;j<=s;j++){
			for(int k=1;k<=3;k++){
				if(b[j][k]>=0){
					ans+=b[j][k];
				}
			}
		}cout<<ans<<"\n";
		for(int j=1;j<=s;j++){
			for(int k=1;k<=3;k++){	
				b[j][k]=0;
				c[j][k]=0;
			}
		} 
	}
	return 0;
}
