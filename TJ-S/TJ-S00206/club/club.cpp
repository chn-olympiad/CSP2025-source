#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
const int MAXN=1000001;
int sum=0,t,n,a[MAXN],b[MAXN],c[MAXN],aa=1,bb=0,cc=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=0;j<3;j++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sum=a[j];
		for(int i=0;i<n;i++){
			if(j!=i&&aa<=n/2){
				sum+=a[i];
				aa++;
			}else if(aa<=n/2){
				i++;
				sum+=a[i];
				aa++;
			}
			for(int x=0;x<n;x++){
				if((j!=i&&j!=x)&&(i!=x&&bb<=n/2)){
					sum+=b[x];
					bb++;
				}else if(j!=i&&bb<=n/2){
					for(int iii=1;iii<=n;iii++){
						if(x==i&&x==j) x++;
					}				
					sum+=b[x];
					bb++;
				}
				for(int k=0;k<n;k++){
					if(((j!=i&&j!=x)&&(i!=x&&j!=k))&&((i!=k&&x!=k)&&cc<=n/2)){
						sum+=c[k];
						cc++;
					}else if((j!=i&&j!=x)&&(i!=x&&cc<=n/2)){
						for(int ii=1;ii<=n;ii++){
							if(j==k&&(i==k&&x==k)) k++;
						}
						sum+=c[k];
						cc++;
					}
				}
			}
		}
		a[j]=sum;
		sort(a,a+3);
		cout<<a[2]<<endl;
		sum=0;
	}
	return 0;
}
