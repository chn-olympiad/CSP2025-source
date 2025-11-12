#include<bits/stdc++.h>
using namespace std;
int m[10000005];
int sum=0;
int n;
void ans(int sl){
	long long maxl=0;
	for(int i=n;i>=n-sl;i--){
		maxl+=m[i];
	}
	int xz=sl;
	long long gs=0;
	if(sl==3){
		for(int i=n;i>=1;i--){
			for(int j=n-1;j>=1;j--){
				for(int k=n-2;k>=1;k--){
					if(m[k]>m[i]-m[j]&&m[i]+m[j]<m[k]){
						if(m[k]+m[j]+m[i]>maxl*2){
							sum++;
						}
					}
				} 
			}
		}
	}
}
long long a=1,b=1,c=1;
void jc(int zz){
	for(int i=1;i<=n;i++){
		a*=i;
	}
	for(int i=1;i<=zz;i++){
		b*=i;
	}
	for(int i=1;i<=n-zz;i++){
		c*=i;
	}
	sum+=a/(b*c);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	sort(m+1,m+n+1);
	ans(3);
	for(int i=4;i<=10;i++){
		jc(i);
		a=1;
	 	b=1;
	 	c=1;
	}
	cout<<sum%998%244%353;
}
