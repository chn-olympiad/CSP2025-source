#include<bits/stdc++.h>
using namespace std;
long long T,n,sum,sum1,sum2,sum3,x,y,z,a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		sum=sum1=sum2=sum3=0;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			if(x>y&&x>z){
				a[i]=x;
				b[i]=1;
				sum1++;
				c[i]=min(x-y,x-z);
			}
			else if(y>z){
				a[i]=y;
				b[i]=2;
				sum2++;
				c[i]=min(y-x,y-z);
			}
			else{
				a[i]=z;
				b[i]=3;
				sum3++;
				c[i]=min(z-x,z-y);
			}
			sum+=a[i];
		}
		if(sum1>n/2){
			sum1=0;
			for(int i=1;i<=n;i++)if(b[i]==1)c[++sum1]=c[i];
			sort(c+1,c+sum1+1);
			for(int i=1;i<=sum1-n/2;i++)sum-=c[i];
		}
		if(sum2>n/2){
			sum2=0;
			for(int i=1;i<=n;i++)if(b[i]==2)c[++sum2]=c[i];
			sort(c+1,c+sum2+1);
			for(int i=1;i<=sum2-n/2;i++)sum-=c[i];
		}
		if(sum3>n/2){
			sum3=0;
			for(int i=1;i<=n;i++)if(b[i]==3)c[++sum3]=c[i];
			sort(c+1,c+sum3+1);
			for(int i=1;i<=sum3-n/2;i++)sum-=c[i];
		}
		cout<<sum<<"\n";
	}
}
