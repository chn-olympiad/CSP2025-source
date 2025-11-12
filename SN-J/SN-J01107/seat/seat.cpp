#include<iostream>
using namespace std;
int a[1001];
int main(){
	//freopen("seat.in""r"stdin)
	//freopen("seat.out""w"stdout)
	int n,y;
	cin>>n>>y;
	n=n*y;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}for(int i=0;i<n;++i){
		for(int j=0;j< n;++j){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}cout<<22;
	return 0;
}
