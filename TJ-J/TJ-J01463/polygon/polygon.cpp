#include<bits/stdc++.h>
using namespace std;
int a[5005];
int b[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	int n;
//	cin>>n;
//	for(int i = 1;i<=n;i++){
//		cin>>a[i];
//		b[i] = b[i-1] + a[i];
//		cout<<b[i]<<" "<<endl;
//	}
//	int sum = 0;
//	for(int i = 3;i<=n;i++){
//		for(int j = 1;j<=n-i+1;j++){
//			int maxx = -1e9;
//			for(int x = 1;x<=i-1;x++){
//				maxx = max(a[j+x],maxx);
//			}
//			cout<<b[j+i-1] - b[j-1]<<" "<<1<<endl;
//			cout<<maxx<<" "<<2<<endl;
//			if(b[j+i-1] - b[j-1] > maxx*2){
//				sum++;
//			}
//		}
//	}
//	cout<<sum%998244353;
	
	int n;
	cin>>n;
	int a,b,c;
	cin>>a>>b>>c;
	int maxx = -1e9;
	maxx = max(max(max(a,b),c),maxx);
	if(a+b+c > maxx * 2){
		cout<<1;
	}else{
		cout<<0;
	}

	
	
	
	
	
	
	
	
	return 0;
} 
