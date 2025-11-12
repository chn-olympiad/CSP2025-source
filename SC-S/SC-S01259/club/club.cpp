#include<bits/stdc++.h>
using namespace std;
int n,a[100000],b[100000],pro,sum;
int u(int e){
	int pro=1;
	for(int i=0;i<e;i++) pro*=3;
	return pro;
}
void p(int m){
	if(b[m]==3){
		b[m]=1;
		p(m-1);
	}
	else{
		b[m]++;
		return ;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	int t;
	cin>>t;
	while(t--){
		pro=0;
		sum=0;
		cin>>n;
		map<int,map<int,int> >k;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				cin>>k[i][j];
		}
		if(n>15){
			int uu[200000];
			for(int i=1;i<=n;i++){
				uu[i]=k[i][1];
			}
			int ooo=0;
			sort(uu+1,uu+n+1);
			for(int i=n;i>=n/2+1;i--) ooo+=uu[i];
			cout<<ooo<<endl;
		}
		else{
			for(int i=1;i<=u(n);i++) b[i]=1;
			while(sum<u(n)){
				int a[4]={0};
				for(int i=1;i<=n;i++){
					//cout<<b[i]<<" ";
					a[b[i]]++;
					if(i==n){
						int sun=0;
						if(a[1]<=n/2&&a[2]<=n/2&&a[3]<=n/2){
							for(int i=1;i<=n;i++){
								sun+=k[i][b[i]];	
							}
						pro=max(sun,pro),sun=0;
						}
						//cout<<endl;
						sum++;
						p(n);
					}
				}
			}
			cout<<pro<<endl;
		}
	}
}