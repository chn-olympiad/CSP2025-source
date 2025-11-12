#include<bits/stdc++.h>
using namespace std;
int m,n;
int main(){
	std::ifstream cin("seat.in");
	std::ofstream cout("seat.out");
	cin>>m>>n;
	int a[m+1][n+1]={-1},b[m*n+1],sum=0,sum1=0,sum2=0;
	for(int i=0;i<m*m;i++){
		cin>>b[i];
	}
	sum2=b[0];
	sort(b+0,b+m*n);
	for(int i=0;i<m;i++){
		sum1=sum+n-1;
		for(int j=0;j<n;j++){
			if(i%2==0){
				a[j][i]=b[sum];
				sum++;
			}
			if(i%2==1){
				a[j][i]=b[sum1];
				sum1--;
				sum++;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[j][i]==sum2) cout<<j+1<<" "<<i;
		}
		cout<<endl;
	}
	return 0;
}
