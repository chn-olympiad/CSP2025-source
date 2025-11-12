#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int m,n,a[10005],x=0,q=0;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		int q=a[i];
		if(q==n){
			x++;
		}
		for(int j=i;j<m-1;j++){
			q=q+a[j];
			if(q==n||a[i]+a[j]==n){
				x++;
			}
		}
	}
	cout<<x;
	return 0;
}
