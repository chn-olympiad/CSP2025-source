#include<bits/stdc++.h> 
#include<iostream> 
#include<string> 
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	long long m=0;
	cin>>a;
	int b[a];
	for(int i=1;i<=a;i++){
		cin>>b[i];
	}int c=a;
	for(int i=c;i>=1;i--){
		m+=i;
	}for(int i=1;i<=c;i++){
		for(int j=i+1;j<=c;j++){
			for(int k=j+1;k<=c;k++){
				if(b[i]+b[j]<=b[k]){
					m--;
				}for(int l=k+1;l<=c;l++){
					if(b[i]+b[j]+b[k]<=b[l]){
						m--;
					}for(int n=l+1;n<=c;n++){
					    if(b[i]+b[j]+b[k]+b[l]<=b[n]){
						    m--;
					    }for(int v=n+1;v<=c;v++){
					        if(b[i]+b[j]+b[k]+b[l]+b[n]<=b[v]){
						        m--;
					        }for(int p=v+1;p<=c;p++){
					            if(b[i]+b[j]+b[k]+b[l]+b[n]+b[v]<=b[p]){
						            m--;
					            }for(int o=p+1;o<=c;o++){
					                if(b[i]+b[j]+b[k]+b[l]+b[n]+b[v]+b[p]<=b[o]){
						                m--;
					                }for(int q=o+1;q<=c;q++){
					                    if(b[i]+b[j]+b[k]+b[l]+b[n]+b[v]+b[p]+b[o]<=b[q]){
						                    m--;
					                    }for(int y=q+1;y<=c;y++){
					                    	if(b[i]+b[j]+b[k]+b[l]+b[n]+b[v]+b[p]+b[o]+b[q]<=b[y]){
						                        m--;
					                        }
										}
				                    }
				                }
				            }
				        }
				    }
				}
			}
		}
	}int r=(m+1)%998244353;
	cout<<r;
	return 0;
}
