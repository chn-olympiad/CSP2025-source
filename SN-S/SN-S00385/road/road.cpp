#include<bist/stdc++.h>
using namespace std;
int n,m,sum;
int s[501];
int c[501];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
		cin>>c[i];
		if(c[i]>=s[i]){
			sum+=1;
		}
	}
	cout<<sum;
	return 0;
}
