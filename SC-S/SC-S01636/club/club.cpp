#include<iostream>
using namespace std;
int main(){
	int n,t,a,b,c,l,d[10005],e[10005],f[10005];
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int mx=n/2,sum=0;
		for(int j=1;j<=n;j++){
			cin>>a>>b>>c;
			d[j]=a;
			e[j]=b;
			f[j]=c;
		}
		for(int g=n;g>0;g--){
			if(d[g]<d[g-1]){
				int s=d[g];
				d[g]=d[g-1];
				d[g-1]=s;
			}
		}
		for(int h=n;h>0;h--){
			if(e[h]<e[h-1]){
				int r=e[h];
				e[h]=e[h-1];
				e[h-1]=r;
			}
		}
		for(int k=n;k>0;k--){
			if(f[k]<f[k-1]){
				int l=f[k];
				f[k]=f[k-1];
				f[k-1]=l;
			}
		}
		for(int x=1;x<=mx;x++){
			sum+=d[x];
			sum+=e[x];
			sum+=f[x];
		}
		cout<<sum<<endl;
	}
	return 0;
} 