#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int max,n,i,ga1,ga2,ga3,gb1,gb2,gb3,gc1,gc2,gc3,gd1,gd2,gd3,maxa,maxb,maxc,maxd;
	cin>>n>>i;
	cin>>ga1>>ga2>>ga3;
	cin>>gb1>>gb2>>gb3;
	cin>>gc1>>gc2>>gc3;
	cin>>gd1>>gd2>>gd3;
	if(ga1>=ga2&&ga1>=ga3){
		maxa=ga1;
	}
	else if(ga2>=ga1&&ga2>=ga3){
		maxa=ga2;
	}
	else if(ga3>=ga1&&ga3>=ga2){
		maxa=ga3;
	}
	else if(gb1>=gb2&&gb1>=gb3){
		maxb=gb1;
	}
	else if(gb2>=gb1&&gb2>=gb3){
		maxb=gb2;
	}
	else if(gb3>=gb1&&gb3>=gb2){
		maxb=gb3;
	}
	else if(gc1>=gc2&&gc1>=gc3){
		maxc=gc1;
	}
	else if(gc2>=gc1&&gc2>=gc3){
		maxc=gc2;
	}
	else if(gc3>=gc1&&gc3>=gc2){
		maxc=gc3;
	}
	 else if(gd1>=gd2&&gd1>=gd3){
		maxd=gd1;
	}
	else if(gd2>=gd1&&gd2>=gd3){
		maxd=gd2;
	}
	else if(gd3>=gd1&&gd3>=gd2){
		maxd=gd3;
	}
	max=maxa+maxb+maxc+maxd;
	cout<<max;
return 0;
}
