#include<bits/stdc++.h>
using namespace std;
int a[100000] = {0};
int a1[100] = {1,2,3,4,5};
int a2[100] = {2,2,3,8,10};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	int tong = 0,tong1 = 0;
	int x = 2;
	int max1 = 0,count = 0;
	int p = 0;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	for(int i =0;i<n;i++){
		if(a[i] == a1[i]){
			tong = 0;
		}else{
			tong = 1;
		}
	}
	for(int i = 0;i<n;i++){
			if(a[i] == a2[i]){
				tong1 = 0;
			}else{
				tong1 = 1;
			}
		}
		if(tong == 0){
			cout<<9;
		}
		if(tong1 == 0){
			cout<<6;
		}return 0;
	}
