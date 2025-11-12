#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110],f=0;
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1);
	for(int j=m;j>=1;j--){
		if(j%2==1){
			for(int i=n;i>=1;i--){
				sum++;
				if(a[sum]==r){
					cout<<j<<' '<<i;
					f=1;
					break;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				sum++;
				if(a[sum]==r){
					cout<<j<<' '<<i;
					f=1;
					break;
				}
			}
		}
		if(f==1) break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
