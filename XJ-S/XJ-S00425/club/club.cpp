#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct man{
	int a_1,a_2,a_3;
	int maxx,midd,minn;
};

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		man peo[n+1];
		for(int a=1;a<=n;a++){
			cin>>peo[a].a_1>>peo[a].a_2>>peo[a].a_3;//对a b c部门的满意度 
			peo[a].maxx=max(peo[a].a_1,max(peo[a].a_2,peo[a].a_3));//最大的满意度 
			peo[a].minn=min(peo[a].a_1,min(peo[a].a_2,peo[a].a_3));//最小的满意度 
			peo[a].midd=(peo[a].a_1+peo[a].a_2+peo[a].a_3)-(peo[a].maxx+peo[a].minn);//中间的满意度 
		}
		int ja=0,jb=0,jc=0;//计a b c部门人数 
		long long int x=0;//满意度之和 
		for(int a=1;a<=n;a++){//对n个人选择最优部门 
			if(peo[a].maxx==peo[a].a_1){//对a部门最满意 
				if(ja<=n/2){//a部门人未满 
					x+=peo[a].maxx;
				}
				else{//a部门人已满
					if(peo[a].midd==peo[a].a_2){//对b部门最满意 
						if(jb<=n/2){//b部门人未满 
							int acha=peo[a].maxx-peo[a].midd;//对a b部门满意度之差 
							int bcha=0,bxb=0;//b对a b部门满意度之差  记b 
							for(int b=1;b<=n;b++){
								if(b!=a){
									bcha=min(bcha,(peo[a].maxx-peo[a].midd));
								}
							}
							for(int b=1;b<=n;b++){//寻找最小b下标 
								if(b!=a&&bcha==peo[a].maxx-peo[a].midd){
									bxb=b;
								}
							}
							if(bcha<=acha){
								x-=peo[bxb].maxx;
								x+=peo[bxb].midd;
								x+=peo[a].maxx;
							}
							else{
								x+=peo[a].midd;
							}
						}
						else if(peo[a].minn==peo[a].a_3){//b部门人已满（只剩c部门）
							int acha=peo[a].midd-peo[a].minn;//对a b部门满意度之差 
							int bcha=0,bxb=0;//b对a b部门满意度之差  记b 
							for(int b=1;b<=n;b++){
								if(b!=a){
									bcha=min(bcha,(peo[a].midd-peo[a].minn));
								}
							}
							for(int b=1;b<=n;b++){//寻找最小b下标 
								if(b!=a&&bcha==peo[a].midd-peo[a].minn){
									bxb=b;
								}
							}
							if(bcha<=acha){
								x-=peo[bxb].midd;
								x+=peo[bxb].minn;
								x+=peo[a].midd;
							}
							else{
								x+=peo[a].minn;
							}
						}
					}	
				}
			}
			else if(peo[a].maxx==peo[a].a_2){//对b部门最满意 
				if(jb<=n/2){//b部门人未满 
					x+=peo[a].maxx;
				}
				else{//b部门人已满(只剩c部门)
					int acha=peo[a].maxx-peo[a].midd;//a对b c部门满意度之差 
					int bcha=0,bxb=0;//b对b c部门满意度之差  记b 
					for(int b=1;b<=n;b++){
						if(b!=a){
							bcha=min(bcha,(peo[a].maxx-peo[a].midd));
						}
					}
					for(int b=1;b<=n;b++){//寻找最小b下标 
						if(b!=a&&bcha==peo[a].maxx-peo[a].midd){
							bxb=b;
						}
					}
					if(bcha<=acha){
						x-=peo[bxb].maxx;
						x+=peo[bxb].midd;
						x+=peo[a].maxx;
					}
					else{
						x+=peo[a].midd;
					}	
				}
			}
			else{//对c部门最满意 
				x+=peo[a].maxx;
			}
		}
		cout<<x<<endl; 
	}
		
	return 0;
} 
