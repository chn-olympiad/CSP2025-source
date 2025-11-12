#include<bits/stdc++.h>
using namespace std;
int a[10005];
struct knx{
	int mx=0;
	int t=0;//情况
 	int bn[5005];//边之和
	int bl[5005];//边数之和
};
knx c[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sum=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i].mx=a[i];
		c[i].bn[1]=1;
		c[i].bl[1]=a[i];
		int t1=1;
		for(int j=1;j<i;j++){
			for(int k=1;k<=c[j].t;k++){
				t1++;
				c[i].bl[t1]+=c[j].bl[k];
			}
		}
	}

	return 0;
}