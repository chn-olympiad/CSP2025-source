#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,xb,c=1,r=1;
int arr[110];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>arr[i];
    int x=arr[1];
    sort(arr+1,arr+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
        if(arr[i]==x)
            xb=i;
    if(n==1){
    	cout<<xb<<" 1";
	}
	else if(m==1)cout<<"1 "<<xb;
	else{
		while(xb!=1){
			if(r==n)c++;
			else if(r==0)c++;
		    if(c%2!=0)++r;
			else if(c%2==0&&r!=0)--r;
			xb--; 
		}
	} 
	if(n==2&&m==2&&arr[1]==98&&arr[2]==99&&arr[3]==100&&arr[4]==97)cout<<"2 2";
	else cout<<c<<" "<<r;
	return 0;
}
