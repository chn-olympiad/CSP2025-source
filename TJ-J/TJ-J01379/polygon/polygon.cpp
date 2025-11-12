#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int sum;
	int a[5010];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}int l=0,r=n;
	for(int i=1;i<=n;i++){
		for(int i=l;i<=r;l++){
			int max=0;
			int total=0;
			if(a[i]>max){
				max=a[i];
			}total+=a[i];
			if(total>max*2||total==max*2){
				sum+=1;
				
			}break;
	}
		}
	cout<<sum;
	return 0;
}

