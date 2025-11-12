#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0;
	cin>>n;
	int x[501];
	if(n<3){
		cout<<0; 
	}else{
		for(int i=0;i<n;i++){
			int ls;
			cin>>ls;
			x[ls]++;
		}
		sort(x,&x[n],cmp);
	}
	return 0;
} 
