#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m,l=0,k=0,u=0,num=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		for(int j=1;j<=m;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(max(a[j],max(b[j],c[j]))==a[j]){
				if(l<m/2){
					l++,num+=a[j];
				}else if(l>=m/2 and max(b[j],c[j])==b[j]){
					if(k<m/2){
						k++,num+=b[j];
					}else{
						u++,num+=c[j];
					}
				}
			}else if(max(b[j],max(a[j],c[j]))==b[j]){
				if(k<m/2){
					k++,num+=b[j];
				}else if(k>=m/2 and max(a[j],c[j])==a[j]){
					if(l<m/2){
						l++,num+=a[j];
					}else{
						u++,num+=c[j];
					}
				}
			}else if(max(c[j],max(a[j],b[j]))==c[j]){
				if(u<m/2){
					u++,num+=c[j];
				}else if(k>=m/2 and max(a[j],b[j])==a[j]){
					if(l<m/2){
						l++,num+=a[j];
					}else{
						k++,num+=b[j];
					}
				}
			}
		}
		cout<<num<<endl;
		num=0;
		l=0,k=0,u=0;
	}
	return 0;
} 
