#include<bits/stdc++.h>
using namespace std;

//原本想提供压缩包的，结果发现800kb的压缩包变成了2mb，炸了

//算了，写不动邮寄了。。。 

int n;
int a[5005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	
	if(n==3){
		if(a[0]+a[1]+a[2]>2*max(max(a[0],a[1]),a[2])){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	else if(n==3){
		
	}
	
	return 0;
}
