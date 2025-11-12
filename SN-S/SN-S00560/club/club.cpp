#include<bits/stdc++.h>
using namespace std;
int t,n,e=0,a1[100000]={0},a2[100000]={0},a3[100000]={0},c[3]={0},d1[100000]={0},d2[100000]={0},d3[100000]={0},f=0;
int cdzh(int a[]){
	sort(a,a+3);
	return a[1];
}
void pd3(int a,int b,int d){
	switch(a){
		case 1:c[0]++,e+=d;break;
		case 2:c[1]++,e+=d;break;
		case 3:c[2]++,e+=d;break;
	}
}
void pd2(int a,int b,int d,int f){
	switch(a){
		case 1:c[0]++,e+=d;break;
		case 2:c[1]++,e+=d;break;
		case 3:c[2]++,e+=d;break;
	}
	for(int i=0;i<3;i++){
		if(c[i]>b){
			e-=d;
			pd3(f,b,d);
		}
	}
}
void pd1(int a,int b,int d,int f,int g){
	switch(a){
		case 1:c[0]++,e+=d;break;
		case 2:c[1]++,e+=d;break;
		case 3:c[2]++,e+=d;break;
	}
	for(int i=0;i<3;i++){
		if(c[i]>b){
			e-=d;
			pd2(f,b,d,g);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]=max(a1[i],max(a2[i],a3[i]))){
				d1[i]=1,f=a1[i];
			}else if(a2[i]=max(a1[i],max(a2[i],a3[i]))){
				d1[i]=2,f=a2[i];
			}else{
				d1[i]=3,f=a3[i];
			}
			if(a1[i]=min(a1[i],min(a2[i],a3[i]))){
				d3[i]=1,f=a1[i];
			}else if(a2[i]=min(a1[i],min(a2[i],a3[i]))){
				d3[i]=2,f=a2[i];
			}else{
				d3[i]=3,f=a3[i];
			}
			int b[3]={a1[i],a2[i],a3[i]};
			if(a1[i]=cdzh(b)){
				d2[i]=1,f=a1[i];
			}else if(a2[i]=cdzh(b)){
				d2[i]=2,f=a2[i];
			}else{
				d2[i]=3,f=a3[i];
			}
			pd1(d1[i],n/2,f,d2[i],d3[i]);
			cout<<e<<"\n";			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;			
}
