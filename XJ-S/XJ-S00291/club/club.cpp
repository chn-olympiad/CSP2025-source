#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,a[3],t,m,v,s1,s2,s3,w,q[100001],l;
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		s1=s2=s3=w=0;
		l=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[j];
			}
			m=max(a[1],a[2]);
			v=max(m,a[3]);
			if(s1>n/2) v=max(a[2],a[3]);
			if(s2>n/2) v=max(a[1],a[3]);
			if(s3>n/2) v=max(a[1],a[2]); 
			if(v==a[1]){
				s1++;
				w+=a[1];
			}
			if(v==a[2]){
				s2++;
				w+=a[2];
			}
			if(v==a[3]){
				s3++;
				w+=a[3];
			}
		}q[l]=w;
		l++;
	}
	for(int i=1;i<=t;i++) cout<<q[i]<<endl;
	return 0;
}
