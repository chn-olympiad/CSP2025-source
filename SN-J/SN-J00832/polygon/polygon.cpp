#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],t,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	t=n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=j;k<n;k++){
				for(int l=k;l<n;l++){
					for(int m=l;m<n;m++){
						sort(a,a+n,cmp);
						if(a[i]+a[j]+a[k]+a[l]+a[m]>a[0]){
							r++;
						}
					}
				}
			}
		}
	}
	cout<<r;
	return 0;
}
