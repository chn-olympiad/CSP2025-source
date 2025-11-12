#include<bits/stdc++.h>
using namespace std;
int a11[100010],a22[100010],a33[100010]/*,ma[100010],mi[100010],mid[100010]*/;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,x,c11=0,c22=0,c33=0,ma11=-1,ma22=-1,ma33=-1,maxx=-1;
		long long cnt=0;
		cin>>n;
		x=n/2;
		for(int i=0;i<n;i++){
			cin>>a11[i]>>a22[i]>>a33[i];/*
			ma[i]=max(a1[i],max(a2[i],a3[i]));
			mi[i]=min(a1[i],min(a2[i],a3[i]));
			mid[i]=a1[i]+a2[i]+a3[i]-ma-mi;*/
			ma11=max(ma11,a11[i]);
			ma22=max(ma22,a22[i]);
			ma33=max(ma33,a33[i]);
		}
		if(n==2){
			int b11=max(a11[0],max(a22[0],a33[0])),maxx1,maxx2;
			if(b11==a11[0]){
				int c01=max(a22[1],a33[1]);maxx1=b11+c01;
			}
			if(b11==a22[0]){
				int c01=max(a11[1],a33[1]);maxx1=b11+c01;
			}
			if(b11==a33[0]){
				int c01=max(a11[1],a22[1]);maxx1=b11+c01;
			}
			int c22=max(a11[1],max(a22[1],a33[1]));
			if(c22==a11[1]){
				int b02=max(a22[0],a33[0]);maxx2=c22+b02;
			}
			if(c22==a22[1]){
				int b02=max(a11[0],a33[0]);maxx2=c22+b02;
			}
			if(c22==a33[1]){
				int b02=max(a11[0],a22[0]);maxx2=c22+b02;
			}
			cout<<max(maxx1,maxx2)<<endl;
			continue;
		}
	}
	return 0;
}
