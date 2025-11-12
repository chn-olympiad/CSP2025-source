#include<bits/stdc++.h>
using namespace std;
int a[110], x[110], z;
int maxn=-1;
int d[110],d1=1;
int main(){
	freopen("seat.in", "r",stdin);
	freopen("seat.out", "w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>a[i];
	}
	for(int i=1; i<=110;i++){
		if(d1<n){
			d[i]=d1;
			d1++;
		}else if(d1==n){
			d[i]=d1;
			i++;
			d[i]=d1;
			d1--;
			i++;
			for(int j=0; j<=110; j++){
				if(d1!=1){
					d[i]=d1;
					i++;
					d1--;
				}else{
					break;
				}
			}
			d[i]=1;
		}
	}
	int w=a[1];
	for(int i=1; i<=n*m; i++){
		for(int j=1; j<=n*m; j++){
			if(a[j]>maxn){
				maxn=a[j];
				z=j;
			}
		}
		a[z]=-1;
		x[i]=maxn;
		maxn=-1;
	}
	for(int i=1; i<=n*m; i++){
		if(x[i]==w){
			if(i<=n){
				cout<<"1"<<" "<<i<<endl;
				return 0;
			}else{
				cout<<i/n+1<<" ";
			}
			cout<<d[i]<<endl;
		}
	}
	return 0;
} 
