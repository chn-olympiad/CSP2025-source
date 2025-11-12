#include<bits/stdc++.h>
using namespace std;

long long n,a[5005],b[5005],c[5005],aaa,bbb,su=0,ma=0,fff=1,summm=0,summ;
long long l(long long a1,long long b1/*max*/,long long c1/*sum*/,long long d1){
//	cout<<"!!! "<<a1<<" "<<b1<<" "<<c1<<" "<<d1<<" "<<endl;
//			for(long long i=1;i<=n;i++){
//				if(b[i]==1){
//					cout<<i<<" ";
//				}
//				
//			}
//			cout<<endl;
	long long suu=0;
	if(a1==0){
		if(c1-2*b1>0&&n-a1>=3){
//			for(long long i=1;i<=n;i++){
//				if(b[i]==1){
//					cout<<i<<" ";
//				}
//			}
//			cout<<endl;
			return 1;
		}
	}
	if(c1-2*b1>0&&n-a1>=3){
//		for(long long i=1;i<=n;i++){
//			if(b[i]==1){
//				cout<<i<<" ";
//			}
//			
//		}
//		cout<<endl;
		suu++;
	}

	for(long long i=d1+1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			suu+=l(a1-1,max(b1,a[i]),c1+a[i],i);
			suu%=998244353;
			b[i]=0;
//			for(long long j=i+1;j<=n;j++){
//				if(a[j]!=a[i]){
//					i=j;
//					break;
//				}
//			}

		}
	}
	return suu;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;

	for(long long i=1;i<=n;i++){
		cin>>a[i];//4 2 3 
		if(i!=1&&a[i]!=a[i-1]){
			fff=0;
		}
		ma=max(aaa,ma);
	}
	if(fff){
		
		for(long long i=3;i<=n;i++){
			summ=1;
			for(long long j=1;j<=i;j++){
				summ*=(i-j+1);
				summ%=998244353;
			}
			summm+=summ;
			summm%=998244353;
		}
		cout<<summm;
		return 0;
	}
	sort(a+1,a+n+1);
	su=l(n,0,0,0);
	cout<<su;
//	for(long long i=1;i<=n-2;i++){
//		if(a[i]+a[i+1]+a[i+2]>a[i+2]*2){
//			f[i][3].su=1;
//			f[i][3].ma=a[i+2];
//			f[i][3].ch=a[i]+a[i+1]-a[i+2];
//			break;
//		}
//	}
//	for(long long i=3;i<=n;i++){
//		for(long long j=3;j<=n;j++){
//			if((a[i]-f[i-1][j-1].ma)*2<=a[i]){
//				f[i][j].su+=f[i-1][j-1].su;
//				f[i][j].su%=998244353;
//				f[i][j].ma=a[i];
//				f[i][j].ch=f[i-1][j-1].ch+2*f[i-1][j-1].ma-2*a[i];
//			}	
//			if(f[i-1][j].ch-(a[i]-f[i-1][j].ma)*2>=0){
//				f[i][j].su+=f[i-1][j].su;
//				f[i][j].su%=998244353;
//				f[i][j].ch=min(f[i][j],f[i-1][j].ch-(a[i]-f[i-1][j].ma)*2);
//				
//			}
//		}
//	}
//	for(long long i=1;i<=n;i++){
//		sum+=f[n][i].su;
//		sum%=998244353;
//	}
	
	return 0;
}
/*
5
2 2 3 8 10
*/
//
//sum-2ma
//sum-2a[i]
//1 2 3 4 5
//
//2 3 4

//5*4*3*5+5*4*3*2*1
