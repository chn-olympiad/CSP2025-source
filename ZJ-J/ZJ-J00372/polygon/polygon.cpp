#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int a,n[5005],mx,sum,he;
int dg(int t,int wz,int bj){
	if(a-bj-wz==3)return 0;
	for(int i=wz;i<a-bj;i++){
		t+=n[i];
		if(mx<he-t){
			sum++;	
		}
		dg(t,i+1,bj);
		t-=n[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		scanf("%d",&n[i]);
		he+=n[i];
	}
	sort(n,n+a);
	for(int i=0;i<=a-3;i++){
		mx=n[a-1-i]*2;
		if(he>n[a-1]*2)sum++;
		dg(0,0,i);
		he=he-(mx/2);
	}
	cout<<sum;
	return 0;
}
