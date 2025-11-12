//SN-J00881，纪柯元，西安市曲江第一中学// 
#include<bits/stdc++.h>
using namespace std;
int qiuhe(int a[500],int u,int i){

	int shuzi=0;
	if(u<i){for(int q=u;q<=i;q++){
		shuzi=shuzi+a[q];
	}
	
	}
	else{
		for(int q=i;q<=u;q++){
			shuzi=shuzi+a[q];
		}
	}
	return shuzi;
}
int main(){
	int n;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int a[500]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	int number=0;
	for(int i=3;i<=n;i++){
		if(i==n){
			number++;
			break;
		}
		for(int j=1;j<=n-i+1;j++){
			for(int k=2;k<=n-i+1;k++){
				if(qiuhe(a,k,k+i-1)+a[j]>2*a[k+i-1]){
			number++;
			}
		}
		}
		}
		
	
	cout<<number;
	
}
