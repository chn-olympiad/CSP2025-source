#include<bits/stdc++.h>
using namespace std;
int a[110],b[11][11],c[11];
int n,m,k,w,s,mc;
int cmp(int a,int b) {
	return a>b;
}
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n==1&&m==1) {
		cout<<"1 1";
		return 0;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>b[i][j];
			a[k]=b[i][j];
			if(i==1&&j==1) {
				s=a[k];
			}
			k++;
		}
	}
	sort(a,a+100,cmp);
	for(int i=0;i<k;i++) {
		if(a[i]==s)  {
			mc=i;
			break;
		}
	}
	int g=(mc+n)/n;
	for(int i=(g-1)*n;i<=g*n-1;i++) {
		c[w]=a[i];
		w++;
	}
	if(g%2==1) {
		sort(c,c+w,cmp);
	}
	else sort(c,c+w);
	for(int i=0;i<w;i++) {
		if(c[i]==s) {
			cout<<g<<" "<<i+1;
			break;
		}
	}
	return 0;
}
