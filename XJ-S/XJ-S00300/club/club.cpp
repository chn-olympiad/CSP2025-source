#include<bits/stdc++.h>
using namespace std;
int a[1001];
int b[100][4];
int maxx[101],c,l[101],t[99];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		
		cin>>a[i];
		c=0;
		for(int j=0;j<a[i];j++){
			for(int k=0;k<3;k++){
				cin>>b[j][k];
			}
		}
		c=0;
		for(int j=0;j<a[i];j++){
			c=0;
			for(int k=0;k<3;k++){
				c=0;
				if(b[j][k]>c){
					c=b[j][k];
					l[j]=k;
				}	
			    maxx[j]=c;
			}
		}
		
		if(l[0]<3&&l[1]<3&&l[2]<3){
			
			for(int j=0;j<a[i];j++){
				c=c+maxx[j];
			}	
		}
	    t[i]=c;
	}
	c=0;
	for(int i=0;i<=n;i++){
		cout<<t[i]<<endl; 
	}
	return 0;
}
