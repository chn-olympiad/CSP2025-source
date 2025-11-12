#include<bits/stdc++.h> 
using namespace std;
long long t,n,a[100010][4];
long long bm[4];//部门 
long long wy[100010];
long long sum;
bool f1,f2,f3;

long long zd(long long x,long long y,long long z){
	long long c,cc;
	if(x>y) c=x,cc=1;
	else c=y,cc=2;
	if(z>c) return 3;
	else return cc;
}
long long zj(long long x,long long y,long long z){
	if(x<y&&x>z || x<z&&x>y) return x;
	if(y<x&&y>z || y<z&&y>x) return y;
	if(z<x&&z>y || z<y&&z>x) return z;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		f1=0,f2=0,f3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3]; 
			if(a[i][1]!=0) f1=1;
			if(a[i][2]!=0) f2=1;
			if(a[i][3]!=0) f3=1;
			bm[zd(a[i][1],a[i][2],a[i][3])]++;
			long long d=a[i][zd(a[i][1],a[i][2],a[i][3])];
			sum=sum+d;
		}
		if(bm[1]<=n/2&&bm[2]<=n/2&&bm[3]<=n/2){
			cout<<sum<<"\n";
			continue;
		}
		if(n==2){
			long long sum1=0,sum2=0;
			long long d;
			sum1=a[1][zd(a[1][1],a[1][2],a[1][3])];
			sum2=a[2][zd(a[2][1],a[2][2],a[2][3])];
			d=zd(a[2][1],a[2][2],a[2][3]);
			long long e=zj(a[2][1],a[2][2],a[2][3]);
			sum1=sum1+e;
			d=zd(a[1][1],a[1][2],a[1][3]);
			e=zj(a[1][1],a[1][2],a[1][3]);
			sum2=sum2+e;
			if(sum1>=sum2) sum=sum1;
			else sum=sum2;
			cout<<sum<<"\n";
			continue;
		}
		if(!f1&&!f3){
			sum=0;
			for(int i=1;i<=n;i++){
				wy[i]=a[i][2];
				
			}
			sort(wy+1,wy+1+n);
			for(int i=n;i>n/2;i--){
				sum=sum+wy[i];
				//cout<<wy[i]<<" ";
			}
			cout<<sum<<"\n";
			continue;
		}
		if(!f2&&!f3){
			sum=0;
			for(int i=1;i<=n;i++){
				wy[i]=a[i][1];
			}
			sort(wy+1,wy+1+n);
			for(int i=n;i>=n/2;i++){
				sum+=wy[i];
			}
			cout<<sum<<"\n";
			continue;
		}
		if(!f2&&!f1){
			sum=0;
			for(int i=1;i<=n;i++){
				wy[i]=a[i][3];
			}
			sort(wy+1,wy+1+n); 
			for(int i=n;i>=n/2;i++){
				sum+=wy[i];
			}
			cout<<sum<<"\n";
			continue;
		}
		cout<<sum<<"\n";
	}
	return 0;
}