//LiuShaoAng SN-J00098 XiAnFuLun
#include<bits/stdc++.h>
using namespace std;
const int N= 6000;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin.tie(0);
	int n,count = 0;
	long long a[N];
	cin>>n;int count_1=0;int count_2=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<n;++i){
		if(a[i]+a[i+1]>a[i+2]){
			count++;
		}
		if(a[i]+a[i+1]+a[i+2]>a[i+3]){
			
			count_1++;
		}
		if(a[i]+a[i+1]+a[i+2]+a[i+3]>a[i+4]){
			
			count_2++;
		}
	}
	cout<<count+count_1+count_2;
	return 0;
}