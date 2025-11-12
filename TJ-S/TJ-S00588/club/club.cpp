#include<bits/stdc++.h>
using namespace std;
int q(int a,int e,int c){
	
	int max=0;
	int d[3]={a,e,c};
	max=d[0];
	if(d[1]>=max){
		max=d[1];
	}
	if(d[2]>=max){
		max=d[2];
	}
	return max;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m;
	int a[m][3];
	int b[3];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		int sum=0;
		for(int j=0;j<m;j++){
			int f[3]={0};
			for(int o=0;o<3;o++){
				cin>>f[o];
			}
			sum+=*max_element(f,f+3);
			
		}
		cout<<sum<<endl;
	}
	/*int c[3]={0};
		cin>>m;
		for(int j=0;j<m;j++){
			cout<<1<<" ";
			for(int k=0;k<3;k++){
				cin>>a[j][k];
			}
			int b[3];
			for(int k=0;k<3;k++){
				b[k]=a[j][k];
			}
			sort(b,b+3);
			int d[j][3]={0};
			for(int h=0;h<3;i++){
				for(int k=i;k<3;k++){
					if(b[h]==a[j][k]){
						d[j][k]=h;
					}
				}
			}
			for(int k=0;k<3;k++){
				cout<<b[k];
			}
		
			if(c[j]<=m/2){
				
			}
		}*/
	return 0;
} 

