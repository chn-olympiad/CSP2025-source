#include<bits/stdc++.h>
using namespace std;
int gun[5005],gunshu=0;
int k=0,n,as=0;
bool jl[5005];
bool ceshi(){
	if(gunshu<=2){
		return 0;
	}
	int zong=0,_max=0;
	for(int i=0;i<n;i+=1){
		if(jl[i]==1){
			zong+=gun[i];
			if(gun[i]>_max){
				_max=gun[i];
			}
		}
	}
	_max*=2;
	if(_max<zong){
		return 1;
	}
	else{
		return 0;
	}
}
int dg(int z){
	if(z>=n){
		return 0;
	}
	jl[z]=1;
	gunshu+=1;
	if(ceshi()){
		k+=1;
		k=k%998244353;
	}
	dg(z+1);
	jl[z]=0;
	gunshu-=1;
	dg(z+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i+=1){
		cin>>gun[i];
	}
	dg(0);
	cout<<k;
	return 0;
}
