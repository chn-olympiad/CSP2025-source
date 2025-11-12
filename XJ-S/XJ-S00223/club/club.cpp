#include <bits/stdc++.h>
using namespace std;
long long t,n;
long long a[100010][3];

long long ass1[100010],ass2[100010],ass3[100010];
long long num[3];
int flag=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long sum=0;
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++){
			ass1[i]=0;
			ass2[i]=0;
			ass3[i]=0;
			for(int j=1;j<=3;j++){
				a[i][j]=0;
			}
		}
		
		for(int i=1;i<=n;i++){
			cin>>ass1[i]>>ass2[i]>>ass3[i];
			if(ass2[i]!=0 || ass3[i]!=0){
				flag=1;
			}
		}
		for(int i=1;i<=n;i++){
			a[i][1]=ass1[i];
			a[i][2]=ass2[i];
			a[i][3]=ass3[i];
		}
		if(flag==0){
			long long ans=0;
			sort(ass1+1,ass1+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=ass1[i];
			}
			cout<<ans<<endl;
		}else{
			sum=0;
			for(int i=1;i<=n;i++){
				long long maxx=0,maxp;
				for(int j=1;j<=3;j++){
					if(a[i][j]>maxx){
						maxx=a[i][j];
						maxp=j;
					}
				}
				num[maxp]++;
				if(num[maxp]<=n/2){
					sum+=a[i][maxp];
				}
			}
			cout<<sum<<endl;
		}
		
	}

	return 0;
}
