#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a[5],max,number=0;
	cin>>n>>a[5];
	for(int i;i<5;i++){
		int a[i];
		for(int j;j<=4;j++){
			int a[j];
			if(a[i]>a[j]){
				max=a[i];
			}else{
				max=a[j];
			}
		}
  if(a[0]+a[1]+a[2]+a[3]+a[4]>max){
			number++;
		}
}cout<<number;
return 0;}