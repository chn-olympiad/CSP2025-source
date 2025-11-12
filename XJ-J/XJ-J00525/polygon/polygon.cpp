#include<bits/stdc++.h>
using namespace std;
int a[6000]={0};
int b[10000]={0};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long x=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	int c[n+1]={0};
	while(c[n]==0){
		int m=0,s=0,f=0;
		for(int i=0;i<=n;i++){
			if(c[i]){
				a[m]=b[i];
				m++;
			}
		}
		for(int i=0;i<m;i++){
			s+=a[i];
			f=max(f,a[i]);
		}
		if(s>f*2&&m>=3){
			x++;
		}
		c[0]+=1;
		for(int i=0;i<=n;i++){
			if(c[i]==2){
				c[i]=0;
				c[i+1]+=1;
			}
		}
	}
	cout<<x;
	return 0;
}
