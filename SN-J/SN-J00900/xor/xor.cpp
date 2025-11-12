//SN-J00900 胡志豪 汉滨区汉滨初级中学  
#include<vector>
#include<iostream>
#define ll long long

class yihuo{
public:
	int l;
	int r;
};
ll n,K;
std::vector<ll> a;
std::vector<yihuo> ans;
int ans_num;
ll yi(int l,int r){
	ll num=0;
	for(int i=l;i<=r;i++){
		num^=a[i];
	}return num;
}
void di(int i,int num,int r){
	if(i>=ans.size()){
		ans_num=std::max(ans_num,num);
		return;
	}yihuo tme=ans[i];
	if(tme.l>r)di(i+1,num+1,tme.r);
	di(i+1,num,r);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	std::cin>>n>>K;
	for(int i=0;i<n;i++){
		ll tme;
		scanf("%d",&tme);
		a.push_back(tme);
		for(int j=0;j<=i;j++){
			if(yi(j,i)==K){
				yihuo tme;
				tme.l=j;
				tme.r=i;
				ans.push_back(tme);
			}
		}
	}
	di(0,0,-1);
	std::cout<<ans_num;
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
