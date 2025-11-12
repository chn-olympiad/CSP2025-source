#include<bits/stdc++.h>
using namespace std;
	int a1,a2,a3;
int a[100010];
int b[100010];
int c[100010];
int d[100010];
int e=0,f=0,g=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n; 
		for(int j=1;j<=n;j++){
			cin>>a1>>a2>>a3;
			if(max(a3,max(a1,a2))==a1){
				if(e==n/2){
					for(int k=1;k<=e;k++){
						if(max(a[k],a1)==a1){
							a[k]=a1;
						}
					}
				}
				else{
					e++;
					a[e]+=a1;
				}
			}
			else if(max(a3,max(a1,a2))==a2){
				if(f==n/2){
					for(int k=1;k<=f;k++){
						if(max(b[k],a2)==a2){
							b[k]=a2;
						}
					}
				}
				else{
					f++;
					b[f]+=a2;
				}
			}
			else if(max(a3,max(a1,a2))==a3){
				if(g==n/2){
					for(int k=1;k<=g;k++){
						if(max(c[k],a3)==a3){
							c[k]=a3;
						}
					}
				}
				else{
					g++;
					c[g]+=a3;
				}
			}
		}
		for(int k=1;k<=n/2;k++){
			d[i]+=a[k];
			d[i]+=b[k];
			d[i]+=c[k];
		}
	}
	for(int i=1;i<=t;i++){
		cout<<d[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
