#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;
const int N=1e6+10;
int n,m,k,c; 
struct t3{
	int c1,c2,mo,ms;
}arr[N],b[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>arr[i].c1>>arr[i].c2>>arr[i].mo; 
    for(int i=1;i<=k;i++){
    	cin>>c;
    	for(int j=1;j<=n;j++)
            cin>>b[i].c1>>b[i].c2>>b[i].mo>>b[i].ms;	
	}
	return 0;
}
