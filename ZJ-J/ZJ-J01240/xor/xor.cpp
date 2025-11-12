#include<bits/stdc++.h>
using namespace std;
long long n,k,c,num;
long long a[500010],la=0;
long long f(long long x,long long y){
	long long z=0;
	int ans=1;
	int xx,yy,zz;
	while(x>0||y>0){
		xx=x%2;
		yy=y%2;
		if(xx==yy){
			zz=0;
		}
		else{
			zz=1;
		}
		z+=ans*zz;
		ans*=2;
		x/=2,y/=2;
	}
	return z;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c==k){
			num++;
			la=0;
		}
		else{
			for(int j=la;j>=1;j--){
				if(f(c,a[j])==k){
//					for(int ii=1;ii<=j;ii++){
//						cout<<a[ii]<<" ";
//					}
//					cout<<"/";
//					cout<<f(c,a[j]);
//					cout<<i<<" "<<c<<" "<<j<<endl;
					num++;
					la=0;
				}
				else{
					a[j]=f(c,a[j]);
				}
			}
			la++;
			a[la]=c;
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
