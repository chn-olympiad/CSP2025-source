#include<bits/stdc++.h>
using namespace std;
int n,a[5009],num,maax;
int m(int a[]) {
	int maxx=a[0];
	if(maxx<a[1])maxx=a[1];
	if(maxx<a[2])maxx=a[2];
	return maxx;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	int h=a[0]+a[1]+a[2];
	if(h>m(a)*2)num++;
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
