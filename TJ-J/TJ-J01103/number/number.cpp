#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int a[100];
	for(int i=0;i<=100;i++){
		cin>>a[i];
	}
	for(int i=0;i<=100;i++){
		if(a[i+1]>a[i]){
	        swap(a[i+1],a[i]);
			}
		}
	for(int i=0;i<=100;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
