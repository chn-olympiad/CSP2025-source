#include<bits/stdc++.h>
using namespace std;
int z,n,a[5][100005],b[5][100005],c[5][100005],e,s[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>z;
	for(int q=1;q<=z;q++){
		int a[5][20005]={},b[5][20005]={},c[5][20005]={},e=0,s[5]={};
		cin>>n;
		cin>>a[1][1];
		cin>>a[2][1];
		cin>>a[3][1];
		b[1][1]=a[1][1];
		b[2][1]=a[2][1];
		b[3][1]=a[3][1];
		c[1][1]=1;
		c[2][1]=1;
		c[3][1]=1;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[j][i];
				b[j][i]=a[j][i];
				c[j][i]=i;
				int e=i;
				while(a[j][i]>b[j][i-1]&&i>=2){
					int d=b[j][i-1];
					b[j][i-1]=a[j][i];
					b[j][i]=d;
					int r=c[j][i-1];
					c[j][i-1]=c[j][i];
					c[j][i]=r;
					a[j][i-1]=a[j][i];
					i--;
				}
				i=e;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(b[j][i]!=-1&&s[j]+1<=n/2){
					e+=b[j][i];
					s[j]++;
					b[j][i]=-1;
					int t=c[j][i];
					for(int k=1;k<=3;k++){
						if(k==j&&k==3){
							break;
						}else if(k==j){
							k++;
						}
						for(int o=1;o<=n;o++){
							if(c[k][o]==t){
								b[k][o]=-1;
							}
						}
					}
				}
			} 
			
		}
		cout<<e<<endl;
	}
	return 0;
} 
