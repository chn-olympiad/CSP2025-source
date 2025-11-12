#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,num=0;
	int a[5050];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int j=1;j<=n-1;j++){
		if(a[j]+a[j+1]>a[j+2]&&a[j]+a[j+2]>a[j+1]&&a[j+2]+a[j+1]>a[j]) num++;
	}
	for(int j=1;j<=n-2;j++){
		num++;
	}
	for(int j=1;j<=n-3;j++){
		num++;
	}
	for(int j=1;j<=n-4;j++){
		num++;
	}
	cout<<num+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


