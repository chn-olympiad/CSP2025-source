#include <bits/stdc++.h>
using namespace std;
const int MAX=1e4+5;
int a[MAX][MAX],b[MAX],c[MAX],d[MAX],e[MAX],x[MAX];//a喜爱值，b最高,c人数,d总   
int ans,h,l;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		int maxx=max(a[i][1],a[i][2]);
		b[i]=max(maxx,a[i][3]);
		if(b[i]==a[i][1]) h=1;
		else if(b[i]==a[i][2]) h=2;
		else h=3;
		int minn=min(a[i][1],a[i][2]);
		x[i]=min(minn,a[i][3]);
		if(x[i]==a[i][1]) l=1;
		else if(x[i]==a[i][2]) l=2;
		else l=3;
		e[i]=a[i][6-h-l];
	}  
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(c[j]<=n/2){
				c[j]++;
				if(b[i]==a[i][j]){
					d[j]=max(b[i],d[j]); 
					break;
				}
			}
			else if(c[j]<=n/2){
				c[j]++;
				if(e[i]==a[i][j]){
					d[j]=max(e[i],d[j]); 
					break;
				}
			}
			else if(c[j]<=n/2){
				c[j]++;
				if(x[i]==a[i][j]){
					d[j]=max(x[i],d[j]); 
					break;
				}
			}
		}
	}
	for(int i=1;i<=3;i++){
		ans+=d[i];
	}
	cout<<ans;
	return 0;
}

