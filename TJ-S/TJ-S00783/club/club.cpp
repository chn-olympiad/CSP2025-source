#include<bits/stdc++.h>
using namespace std;
struct kkk{
	short a;short b;short c;
}x[70000];
short a1,a2,a3;
long long sum;
int l1,l2,l3;
int max(int a,int b,int c){
	return max(a,max(b,c));
}
void f1(int l){
	for(int i=0;i<l-1;i++){
		for(int j=0;j<l-1;j++){
			if(x[j].a<x[j+1].a) swap(x[j],x[j+1]);
		}
	}
}
void f2(int l){
	for(int i=0;i<l-1;i++){
		for(int j=0;j<l-1;j++){
			if(x[j].b<x[j+1].b) swap(x[j],x[j+1]);
		}
	}
}
void f3(int l){
	for(int i=0;i<l-1;i++){
		for(int j=0;j<l-1;j++){
			if(x[j].c<x[j+1].c) swap(x[j],x[j+1]);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
for(int T=0;T<t;T++){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a1>>a2>>a3;
		x[i]={a1,a2,a3};
		int m=max(a1,a2,a3);
		if(m==a1) l1++;
		if(m==a2) l2++;
		if(m==a3) l3++;
		sum+=m;
	}
	if(l1>n/2){
		f1(l1);
		for(int i=n/2+1;i<l1;i++){
			sum=sum-max(x[i].a,x[i].b,x[i].c)+max(x[i].b,x[i].c);
		}
	}
	else if(l2>n/2){
		f2(l2);
		for(int i=n/2+1;i<l2;i++){
			sum=sum-max(x[i].a,x[i].b,x[i].c)+max(x[i].a,x[i].c);
		}
	}
	else if(l3>n/2){
		f3(l3);
		for(int i=n/2+1;i<l3;i++){
			sum=sum-max(x[i].a,x[i].b,x[i].c)+max(x[i].a,x[i].b);
		}
	}
	cout<<sum<<endl;
	sum=0;
}
	return 0;
}

