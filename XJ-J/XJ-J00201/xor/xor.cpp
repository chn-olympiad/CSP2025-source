#include<bits/stdc++.h>
using namespace std;
int num[1010];
int sum;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	int max=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n,j++){
			if(num[i]>max)
		}
		if(num[i]+num[i+1]+num[i+2]>max*2){
			sum+=1;
		} 
	}
	cout<<sum;
}
