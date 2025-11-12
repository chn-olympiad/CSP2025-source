//SN-J00900 胡志豪 汉滨区汉滨初级中学  
#include<iostream>
#include<stdio.h>
#include<vector>
#define mod 998244353
#define ll long long

int a[5005],m;
ll n;
void di(int ci,int i,std::vector<int> len){
	if(ci==0){
		ll num=0;
		int maxn;
		for(int j=0;j<len.size();j++){
			num+=len[j];
			maxn=std::max(maxn,len[j]);
		}
		if(num>(2*maxn))n++;
		n%=mod;
		return;
	}
	if(i+ci-1>=m)return;
	di(ci,i+1,len);
	len.push_back(a[i]);
	di(ci-1,i+1,len);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	std::cin>>m;
	for(int i=0;i<m;i++)scanf("%d",&a[i]);
	std::vector<int> tme;
	for(int i=3;i<=m;i++){
		di(i,0,tme);
	}std::cout<<n;
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
