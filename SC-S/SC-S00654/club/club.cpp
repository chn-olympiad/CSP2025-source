#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100],c[100100];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t,n,l1=0,l2=0,l3=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;int al=0,bl=0,cl=0;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(max(a[j],max(b[j],c[j]))==a[j]){
				b[j]=0;
				c[j]=0;
				l1++;
			}else if(max(a[j],max(b[j],c[j]))==b[j]){
				a[j]=0;
				c[j]=0;
				l2++;
			}else if(max(a[j],max(b[j],c[j]))==c[j]){
				b[j]=0;
				a[j]=0;
				l3++;
			}
		}
		sort(a,a+n+1);
		sort(b,b+n+1);
		sort(c,c+n+1);
		
		if(l1>n/2){
			for(int j=l1;j<=100100-(n/2);j++){
				a[j]=0;
			}
		}
		if(l2>n/2){
			for(int j=l2;j<=100100-(n/2);j++){
				b[j]=0;
			}
		}
		if(l3>n/2){
			for(int j=l3;j<=100100-(n/2);j++){
				c[j]=0;
			}
		}
		for(int j=1;j<=100100;j++){
			al=a[j]+al;bl=b[j]+bl;cl=c[j]+cl;
		}
		cout<<al+bl+cl-min(al,min(bl,cl))<<endl;
		
	}
	return 0;
}