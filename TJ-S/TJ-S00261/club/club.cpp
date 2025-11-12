#include<bits/stdc++.h>
using namespace std;
int a[10005][4][10005],b[10005][4][2]={0};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,sum=0;
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1][0]>>a[i][2][0]>>a[i][3][0];
			a[i][1][1]=i;
			a[i][2][1]=i;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(b[i][1][0]<a[j][1][0]){
					b[i][1][0]=a[j][1][0];
					b[i][1][1]=a[j][1][1];
				}
				if(b[i][2][0]<a[j][2][0]){
					b[i][2][0]=a[j][2][0];
					b[i][2][1]=a[j][2][1];
				}
			}
		}
		int x,p=0,q=0;
		int i=1,k=1;
		while(true){
			if(p==m&&q==m) break;
			if(p==m) b[i][1][0]=-2;
			if(q==m) b[k][2][0]=-2;
			if(b[i][1][0]==-1) i+=1;
			if(b[k][2][0]==-1) k+=1;
			if(b[i][1][0]>=b[k][2][0]&&p!=m){
				sum+=b[i][1][0];
				b[i][1][0]=-1;
				x=b[i][1][1];
				for(int j=1;j<=n;j++){
					if(b[j][2][1]==x) b[j][2][0]=-1;
				}
				p+=1;
				i+=1;
			}
			else if(b[i][1][0]<b[k][2][0]&&q!=m){
				sum+=b[k][2][0];
				b[k][2][0]=-1;
				x=b[k][2][1];
				for(int j=1;j<=n;j++){
					if(b[j][1][1]==x) b[j][1][0]=-1;
				}
				q+=1;
				k+=1;	
			}
		}
		cout<<sum<<endl; 
	}
	return 0;
} 
