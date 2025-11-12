//SN-J00251 孙悦翔 西安市曲江第一学校
#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		double p=(a[1]+a[2]+a[3])/2.0;
		if(p>a[1]&&p>a[2]&&p>a[3]){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	return 0;
} 
