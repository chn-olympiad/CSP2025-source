#include<bits/stdc++.h>
using namespace std;
int z,n,a[100005][3],d[100005][3],s[100005],flag1,sum1,sum,cnt[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>z;
	while(z--){
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		sum1=0;
		sum=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][2]!=0||a[i][3]!=0){
					flag1=1;
				}
			}
		}
		if(flag1==0){
			for(int i=1;i<=n;i++){
				s[i]=a[i][1];
			}
			sort(s+1,s+n+1);
			for(int i=n;i>n/2;i--){
				sum1+=s[i];
			}
			cout<<sum1<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				int minn=min(a[i][1],min(a[i][2],a[i][3]));
				d[i][1]=a[i][1]-minn;
				d[i][2]=a[i][2]-minn;
				d[i][3]=a[i][3]-minn;
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cout<<d[i][j]<<" ";
				}
				cout<<endl;
			}
			for(int z=1;z<=n;z++){
				int maxx=0,maxnx=0,maxny=0;
				for(int i=1;i<=n;i++){
					for(int j=1;j<=3;j++){
						if(d[i][j]>maxx){
							maxx=d[i][j];
							maxnx=i;
							maxny=j;
						}
					}
				}
				cout<<maxx<<" "<<maxnx<<" "<<maxny<<endl;
				if(cnt[maxny]<n/2){
					sum=sum+a[maxnx][maxny];
					d[maxnx][1]=d[maxnx][2]=d[maxnx][3]=0;
					cnt[maxny]++; 
				}
				else{
					for(int i=1;i<=n;i++){
						d[i][maxny]=0;
					}
					z--;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
