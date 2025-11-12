#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 5*1e3+10;
int n;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1)
			cnt++; 
	}
	//Ä¾¹÷¶¼ÊÇ1
	if(cnt==n){
		if(n==3)
			printf("1");
		else{
			printf("%d",n*(n-1)*(n-2)/6);
		}
	} 
	return 0;
}
