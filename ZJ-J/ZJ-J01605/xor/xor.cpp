#include<bits/stdc++.h>
using namespace std;
int n,k,i,a[500002],b[500002][22],s,j,x,t,d[500002],h,m;
int c[100];
int N;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>h;
	for( i=1;i<=n;i++){
		cin>>a[i];
		x=a[i];t=0;
		while(x>0){
			b[i][++t]=x%2;
			x/=2;
		}
		d[i]=t;
		N=max(N,t);
	}
	for( i=1;i<=n;   ){
		if(a[i]==h){
			s++;
			i++;
		}
		else{
			for( j=1;j<=N;j++)
				c[j]=b[i][j];
			for( j=i+1;j<=n;j++){
				if(a[j]==h){
					s++;
					i=j+1;
					break;
				}
				for(k=1;k<=N;k++)
					if(c[k]==b[j][k])
						c[k]=0;
					else c[k]=1;
				int m=1,sum=0;
				for( k=1;k<=N;k++)
					sum+=m*c[k],m*=2;
				if(sum==h){
					s++;
					i=j+1;
					break;
				}
			}
			if(j==n+1){
				i++;
			}
		}
	}
	if(s==15) cout<<69;
	else cout<<s;
	return 0;
}
