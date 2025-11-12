#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct lr{
	int l,r;
}qujian;
bool cmp(lr p,lr q){
	return (p.r<q.r)||(p.r==q.r&&p.l<q.l);
}
vector<lr> lfrt;
vector<int> a; 
vector<int> sxor;
int ans=0;
int nxor(int l,int r){
	return sxor[l-1]^sxor[r];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ll,lr,ad=0;
	a.push_back(0);
	sxor.push_back(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>ad;
		int now=sxor.back();
		sxor.push_back(ad^now);
		a.push_back(ad);
		for(int j=i;j>=0;--j){
			if(nxor(j,i)==k){
				qujian.l=j;
				qujian.r=sxor.size()-1;
				lfrt.push_back(qujian);
			}
		}
	}
	sort(lfrt.begin(),lfrt.end(),cmp);
	while(lfrt.size()>0){
		ll=lfrt.back().l;
		lfrt.pop_back();
		ans++;
		while(lfrt.size()>0&&lfrt.back().r>=ll){
			lfrt.pop_back();
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}