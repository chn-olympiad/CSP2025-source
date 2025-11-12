#include<bits/stdc++.h>
using namespace std;
int a[1000001],b[4],c[4],d[4],e[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=a[i];j++){
			cin>>b[j]>>c[j]>>d[j];
			sum+=max(max(b[j],c[j]),d[j]);
			int bj=0,cj=0,dj=0;
			if(max(max(b[j],c[j]),d[j])==b[j]){
				bj++;
			}else if(max(max(b[j],c[j]),d[j])==c[j]){
				cj++;
			}else if(max(max(b[j],c[j]),d[j])==d[i]){
				dj++;
			}
		}
		a[i]=sum;
	} 
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
} 
