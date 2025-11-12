#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int a[105];
int b[15][15];
int n,m,mine;
int i1=1,j1=1,all;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	all=n*m;
	for(int i=1;i<=all;i++) cin>>a[i];
	mine=a[1];
	sort(a+1,a+all+1,greater<int>());
	for(int i=1;i<=all;i++){
		b[i1][j1]=a[i];
		if(a[i]==mine){
			cout<<j1<<" "<<i1;
			return 0;
		}
		if(i1==n&&j1%2==1) j1++;
		else if(i1==1&&j1%2==0) j1++;
		else if(j1%2==0) i1--;
		else if(j1%2==1) i1++;
		else continue;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
