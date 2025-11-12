#include <bits/stdc++.h>
using namespace std;
int n,cnt=0,sum;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int chang=0,max1=0;
	sort(a+1,a+1+n);
	for(int t=3;t<=n;t++){
		chang=0,max1=0,sum=1;
		for(int k=1;k<=n-t;k++){
			for(int i=k;i<=k+t-1;i++){
				if(i>n) break;
				chang+=a[i];
				max1=max(max1,a[i]);
			}
		}
		if(chang>max1*2) cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
