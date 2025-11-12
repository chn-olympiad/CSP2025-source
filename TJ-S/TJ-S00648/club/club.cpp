#include<bits/stdc++.h>
using namespace std;
int main(){
	preopen("club.in","r",stdin);
	preopen("club.out","w",stdout);
	int t,n[100005];
	int a[100005],b[100005],c[100005];
	cin>>t;
	int a1[100005],b1[100005],c1[100005];
	int t1=0;
	int x=0;
	for(int i=0;i<t;i++){
		cin>>n[i];
		for(int j=0;j<n[i];j++){
			cin>>a[x]>>b[x]>>c[x];
		}
	}
	int y=x;
	int x1=0;
	while(y>x/2){
		for(int i=0;i<t;i++){
		    for(int j=0;j<n[i];j++){
			    if(a1[t1]<a[x1]){
			    	a1[t1]=a[x1];
			    	a[x1]=-1;
				}
			    if(b1[t1]<b[x1]){
			    	b1[t1]=b[x1];
			    	b[x1]=-1;
				}
				if(c1[t1]<c[x1]){
					c1[t1]=c[x1];
					c[x1]=-1;
				}
			    x1++;
		    }
	    	t1++;
	    }
	    y--;
	}
	int a2[t],b2[t],c2[t];
	for(int i=0;i<t;i++){
		for(int j=0;j<n[i];j++){
			for(int k=0;k<x/2;k++){
				a2[i]+=a1[k];
				b2[i]+=b1[k];
				c2[i]+=c1[k];
			}
		}
		if(a2[i]>b2[i]&&a2[i]>c2[i])cout<<a2<<endl;
		else if(b2[i]>a2[i]&&b2[i]>c2[i])cout<<b2<<endl;
		else if(c2[i]>a2[i]&&c2[i]>b2[i])cout<<c2<<endl;
	}
	return 0;
}
