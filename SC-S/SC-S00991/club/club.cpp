#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],m1,m2,m3,m;
void pxa(int j){
	int i=j/2;
	while(i){
		if(a[i]<a[j]){
			int a1=a[j],b1=b[j],c1=c[j];
			for(int k=j;k>=i;k--){
				a[k]=a[k-1];
				b[k]=b[k-1];
				c[k]=c[k-1];
			}
			a[i]=a[j];b[i]=b[j];c[i]=c[j];
			j=i;
			i=i/2;
		}
		if(a[i]>a[j]){
			i=i+i/2;
		}
		if(a[i]==a[j]){
			int a1=a[j],b1=b[j],c1=c[j];
			for(int k=j;k>i;k--){
				a[k]=a[k-1];
				b[k]=b[k-1];
				c[k]=c[k-1];
			}
			a[i]=a[j];b[i]=b[j];c[i]=c[j];
			break;
		}
		if(a[j-1]<a[j]&&a[j]<a[j+1])break;
	}
}
void pxb(int j){
	int i=j/2;
	while(i){
		if(b[i]<b[j]){
			int a1=a[j],b1=b[j],c1=c[j];
			for(int k=j;k>i;k--){
				a[k]=a[k-1];
				b[k]=b[k-1];
				c[k]=c[k-1];
			}
			a[i]=a[j];b[i]=b[j];c[i]=c[j];
			j=i;
			i=i/2;
		}
		if(b[i]>b[j]){
			i=i+i/2;
		}
		if(b[i]==b[j]){
			int a1=a[j],b1=b[j],c1=c[j];
			for(int k=j;k>i;k--){
				a[k]=a[k-1];
				b[k]=b[k-1];
				c[k]=c[k-1];
			}
			a[i]=a[j];b[i]=b[j];c[i]=c[j];
			break;
		}
		if(b[j-1]<b[j]&&b[j]<b[j+1])break;
	}
}
void pxc(int j){
	int i=j/2;
	while(i){
		if(c[i]<c[j]){
			int a1=a[j],b1=b[j],c1=c[j];
			for(int k=j;k>=i;k--){
				a[k]=a[k-1];
				b[k]=b[k-1];
				c[k]=c[k-1];
			}
			a[i]=a[j];b[i]=b[j];c[i]=c[j];
			j=i;
			i=i/2;
		}
		if(c[i]>c[j]){
			i=i+i/2;
		}
		if(c[i]==c[j]){
			int a1=a[j],b1=b[j],c1=c[j];
			for(int k=j;k>=i;k--){
				a[k]=a[k-1];
				b[k]=b[k-1];
				c[k]=c[k-1];
			}
			a[i]=a[j];b[i]=b[j];c[i]=c[j];
			break;
		}
		if(c[j-1]<c[j]&&c[j]<c[j+1])break;
	}
}
int main(){
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j]>>b[j]>>c[j];
			
			if(a[j]>b[j]&&a[j]>c[j]){
				m1++;m+=a[j];
			}
			if(a[j]<b[j]&&b[j]>c[j]){
				m2++;m=m+b[j];
			}
			if(c[j]>b[j]&&a[j]<c[j]){
				m3++;m+=c[j];
			}
		}
		for(int j=0;j<n;j++){
			pxa(j);
		}
		if(m1>(n/2)){
			for(;m1>n/2;m1--){
				m-=a[m1];
				if(b[m1]>c[m1]&&m2+1<=n/2){
					m2++;
					m+=b[m1];
				}
				else {m3++;m+=c[m1];
				}
			}
		}
		
		for(int j=0;j<n;j++){
			pxb(j);
		}
		if(m2>(n/2)){
			for(;m2>n/2;m2--){
				m-=b[m2];
				if(a[m2]>c[m2]&&m1+1<=n/2){
					m1++;
					m+=a[m2];
				}
				else {m3++;m+=c[m2];
				}
			}
		}
		for(int j=0;j<n;j++){
			pxc(j);
		}
		if(m3>(n/2)){
			for(;m3>n/2;m3--){
				m-=c[m3];
				if(b[m3]>a[m3]&&m2+1<=n/2){
					m2++;m+=b[m3];
				}
				else{
					m+=a[m3];
				}
			}
		}
		cout<<m<<endl<<endl;
		m=0,m1=0,m2=0,m3=0;
	}
	return 0;
}