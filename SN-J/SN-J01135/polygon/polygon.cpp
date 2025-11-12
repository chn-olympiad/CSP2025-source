#include<bits/stdc++.h>
using namespace std;
int ans,op;
int a[10000010];
bool vis[10000010];
int n;
void d(int x,int z,int y){
	while(y<n){
		for(int i=1;i<=x;i++){
			if(vis[i]==1)	continue;
			else if((a[i]+z)<(z+a[i])/2){
				ans++;
				d(x,z+a[i],y+1);
				
			}
		}
	}
	return;
}
int main(){

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		op+=a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int ww=a[i]+a[j]+a[k];
				if(a[k]<ww/2){
					ans++;
					vis[i]=1;
					vis[j]=1;
					vis[k]=1;
					d(k,ww,3);
					for(int i=1;i<=n;i++)	vis[i]=0;
				}	
			}
		}
	}
	if(a[n]<op/2)	ans++;
	cout<<ans;
	return 0;
}
