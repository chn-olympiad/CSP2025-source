#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int z=0;z<t;z++){
		int n;
		cin>>n;
		int member[n]={},goo[n][3]={},num[n][3]={};
		for(int a=0;a<n;a++){
			cin>>goo[a][0]>>goo[a][1]>>goo[a][2];
			for(int b=0;b<3;b++){
				num[a][b]=b;
			}
			if(goo[a][0]>goo[a][1]){
				swap(num[a][0],num[a][1]);
			}
			if(goo[a][0]>goo[a][2]){
				swap(num[a][0],num[a][2]);
			}
			if(goo[a][1]>goo[a][2]){
				swap(num[a][1],num[a][2]);
			}
		}
		
		int s=0,max=n/2,company[3]={},ans[pow(3,n)];
		while(s<n){
			
		}
	}
	return 0;
}
