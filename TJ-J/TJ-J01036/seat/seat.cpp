#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;//n hang    m lie
	int a[1000];
	cin>>n>>m;
	int x;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0)x=a[i];
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==x){
			int c=i/m+1;
			int r;	
			if(c%2==0)r=i/n+1;
			else{
				r=n-(i/n+1)+1;
			}
			cout<<c<<" "<<r;
		}
		else continue;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

