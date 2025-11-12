#include<bits/stdc++.h>
using namespace std;

const int N=1e+5;

int n;

int f[N+10][3+10];
int p[N+10][3+10];

int sum;
int a[N+10],b[N+10],c[N+10]; 

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;	cin>>t;
	while(t--){
		cin>>n;
		bool f1=1,f2=1,f3=1;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]==0&&c[i]==0)	f1=0;
			else if(a[i]==0&&c[i]==0)	f2=0;
			else if(a[i]==0&&b[i]==0)	f3=0;
			else{
				f1=1;
				f2=1;
				f3=1;
				continue;
			}
		}
			
		if(f1==0){
			sort(a+1,a+n+1);
			long long sum=0;
			for(int i=n;i>n/2;i--){
				sum+=a[i];
			}
			cout<<sum<<endl;
		}else if(f2==0){
			sort(b+1,b+n+1);
			long long sum=0;
			for(int i=n;i>n/2;i--){
				sum+=b[i];
			}
			cout<<sum<<endl;
		}else if(f3==0){
			sort(c+1,c+n+1);
			long long sum=0;
			for(int i=n;i>n/2;i--){
				sum+=c[i];
			}
			cout<<sum<<endl;
		}else{
			int num=n/2;
			int maxv=0;
			int x=0,y=0,z=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					if(x<num&&y<num&&z<num){
						maxv=max(max(f[i-1][1],f[i-1][2]),f[i-1][3]);
						if(maxv==f[i-1][1]){
							x++;
							f[i][j]=maxv+a[i];
						}else if(maxv==f[i-1][2]){
							y++;
							f[i][j]=maxv+b[i];
						}else{
							z++;
							f[i][j]=maxv+c[i];
						} 
					}else if(x<num&&y<num){
						maxv=max(f[i-1][1],f[i-1][2]);
						if(maxv==f[i-1][1]){
							x++;
							f[i][j]=maxv+a[i];
						}else{
							y++;
							f[i][j]=maxv+b[i];
						}
					}else if(x<num&&z<num){
						maxv=max(f[i-1][1],f[i-1][3]);
						if(maxv==f[i-1][1]){
							x++;
							f[i][j]=maxv+a[i];
						}else{
							z++;
							f[i][j]=maxv+c[i];
						}
					}else if(y<num&&z<num){
						maxv=max(f[i-1][2],f[i-1][3]);
						if(maxv==f[i-1][2]){
							y++;
							f[i][j]=maxv+b[i];
						}else{
							z++;
							f[i][j]=maxv+c[i];
						}
					}else if(x<num){
						x++;
						f[i][j]=f[i-1][1]+a[i];
					}else if(y<num){
						y++;
						f[i][j]=f[i-1][2]+b[i];
					}else if(z<num){
						z++;
						f[i][j]=f[i-1][3]+c[i];
					}
				}
			}
			x=0;	y=0;	z=0;
			maxv=0;
			for(int i=n;i>=1;i--){					
				for(int j=1;j<=3;j++){
					if(x<=num&&y<num&&z<num){
						maxv=max(max(p[i+1][1],p[i+1][2]),p[i+1][3]);
						if(maxv==p[i+1][1]){
							x++;
							p[i][j]=maxv+a[i];
						}else if(maxv==p[i+1][2]){
							y++;
							p[i][j]=maxv+b[i];
						}else{
							z++;
							p[i][j]=maxv+c[i];
						} 
					}else if(x<num&&y<num){
						maxv=max(p[i+1][1],p[i+1][2]);
						if(maxv==p[i+1][1]){
							x++;
							p[i][j]=maxv+a[i];
						}else{
							y++;
							p[i][j]=maxv+b[i];
						}
					}else if(x<num&&z<num){
						maxv=max(p[i+1][1],p[i+1][3]);
						if(maxv==p[i+1][1]){
							x++;
							p[i][j]=maxv+a[i];
						}else{
							z++;
							p[i][j]=maxv+c[i];
						}
					}else if(y<num&&z<num){
						maxv=max(p[i+1][2],p[i+1][3]);
						if(maxv==p[i+1][2]){
							y++;
							p[i][j]=maxv+b[i];
						}else{
							z++;
							p[i][j]=maxv+c[i];
						}
					}else if(x<num){
						x++;
						p[i][j]=p[i+1][1]+a[i];
					}else if(y<num){
						y++;
						p[i][j]=p[i+1][2]+b[i];
					}else if(z<num){
						z++;
						p[i][j]=p[i+1][3]+c[i];
					}
				}
			}
			int sum=0,ans=0;
			for(int i=1;i<=3;i++)
				sum=max(sum,f[n][i]);	
			for(int i=1;i<=3;i++)
				ans=max(ans,p[1][i]);	
			cout<<max(ans,sum)<<endl; 
		}
	}
	
	
	
	return 0;
} 