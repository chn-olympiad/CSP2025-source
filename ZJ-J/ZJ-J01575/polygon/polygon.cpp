#include<bits/stdc++.h>
using namespace std;
int n,a[5001]={0};
long long zs=0;
int mmt(int zcd,int mcd,int ng,int jc){
	for(int i=jc+1;i<=n-ng+1;i++){
		if(ng==1){
			if((zcd+a[i])>max(mcd,a[i])*2){
				zs++;
			}
		}
		else{
		    mmt(zcd+a[i],max(mcd,a[i]),ng-1,i);
		}
	}
	return 0;
}
int main(){
	ifstream("poiygon.in");
	ofstream("poiygon.out");
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=n;i>2;i--){
		mmt(0,0,i,0);
	}
	cout<<zs%998244353;
	return 0;
}
