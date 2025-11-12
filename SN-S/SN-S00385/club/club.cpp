#include<bist/stdc++.h>
using namespace std;
int a,b,n[1001];
int sum;
int main(){
	cin>>a>>b;
	for(int i=a;i<n;i++){
		for(int j=b;j<n;j++){
			cin>>n[i][j];
			if(n[i][j]>n[i+1][j]){
				stop(n[i][j],n[i+1][j]);
			}
			sum++;
		}
	}
	cout<<a<<endl<<b<<endl<<sum;
	return 0;
}
