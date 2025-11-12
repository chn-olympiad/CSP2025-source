#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k,sum=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum1=0;
			for(int k=i;k<=j;k++){
			   if(a[i]>=1) sum1++;
			}
		    if(sum1%2==k){
		    	sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
