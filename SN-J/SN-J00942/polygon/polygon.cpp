#include<bits/stdc++.h>
using namespace std;
int n,a[10005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
		for(int j=0;j<n;j++){
			for(int q=0;q<n;q++){
				for(int w=0;w<n;w++){
					int b=max((a[j],a[q]),a[w]);
					if(a[j]+a[q]+a[w]>2*b&&j!=q&&q!=w&&j!=w&&j<q&&q<w){
						ans++;
					}
				}
			}
		}
	for(int y=0;y<n;y++){
		for(int j=0;j<n;j++){
			for(int q=0;q<n;q++){
				for(int w=0;w<n;w++){
					int b=max(((a[j],a[q]),a[w]),a[y]);
					if(a[j]+a[q]+a[w]+a[y]>2*b&&j!=q&&q!=w&&j!=w&&j!=y&&w!=y&&q!=y&&y<j&&j<q&&q<w){
						ans++;
					}
				}
			}
		}
	}
	for(int u=0;u<n;u++){
		for(int y=0;y<n;y++){
			for(int j=0;j<n;j++){
				for(int q=0;q<n;q++){
					for(int w=0;w<n;w++){
						int b=max((((a[j],a[q]),a[w]),a[y]),a[u]);
						if(a[j]+a[q]+a[w]+a[y]+a[u]>2*b&&u!=j&&u!=q&&u!=y&&u!=w&&j!=q&&q!=w&&j!=w&&j!=y&&w!=y&&q!=y&&u<y&&y<j&&j<q&&q<w){
							ans++;
						}
					}
				}
			}
		}
	}
	cout<<ans%998%244%353;
	return 0;
}
