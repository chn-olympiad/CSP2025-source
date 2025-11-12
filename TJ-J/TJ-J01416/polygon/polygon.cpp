#include<bits/stdc++.h>
using namespace std;
int a[100001]={};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005]={},sum=0;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			for(int z=0;z<=n;z++){
				if(i!=j!=z){
					if(i>=j&&i>=z&&i<2*(j+z))sum++;
					if(j>=i&&j>=z&&j<2*(i+z))sum++;
					if(z>=i&&z>=j&&z<2*(i+j))sum++;
				}
			}
		}
	}
	cout<<998244353%sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

