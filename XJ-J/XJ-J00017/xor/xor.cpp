#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;
const int N=100000*5+10; 
int n,k,arr[N],ji;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>arr[i];
    int yhh=0;
    for(int l=1;l<=n;l++)
    	for(int r=l;r<=n;r++){
    		if(l=r&&arr[l]==k)ji++;
			else{
				yhh=arr[l];
    			for(int i=l;i<=r;i++)yhh+=(yhh^arr[i]);
    			if(yhh==k)ji++;
			}
		}
    cout<<ji;
	return 0;
}
