#include <bits/stdc++.h>
using namespace std;
int n,z=0,maxq=0;
int a[10001]={0},b[5]={0};
bool f=true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]+1!=a[i+1]){
			f=false;
		}
	}
	if(f){
		z=2;
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			maxq=max(maxq,a[j]);
			for(int k=j+1;k<=n;k++){
				maxq=max(maxq,a[k]);
				for(int y=k+1;y<=n;y++){
					maxq=max(maxq,a[y]);
					if(i==3 && a[j]+a[k]+a[y]>maxq*2){
						z++;
					}
					for(int ui=y+1;ui<=n;ui++){
						maxq=max(maxq,a[ui]);
						if(i==4 && a[j]+a[k]+a[y]+a[ui]>maxq*2){
							z++;
						}
						for(int yu=ui+1;yu<=n;yu++){
								maxq=max(maxq,a[yu]);
								if(i==5 && a[j]+a[k]+a[y]+a[ui]+a[yu]>maxq*2){
									z++;
								}
						}
					}
				}
			}
		}
	}
	cout<<z;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
