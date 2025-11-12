#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100000];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int xm=a[0];
	sort(a,a+n*m,cmp);
	int k=-1;
	for(int i=0;i<n*m;i++){
		if(a[i]==xm)k=i;
	}
	int mm=k/n+1,nn;
	if(mm%2==1)nn=k%n+1;
	else nn=n-k%n;
	cout<<mm<<' '<<nn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}