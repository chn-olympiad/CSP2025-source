#include<bits/stdc++.h>
using namespace std;
struct hjh{
	int my,bh;bool zx=0;
};
hjh j1[100005];
hjh j2[100005];
hjh j3[100005];
map<int,int>m
bool cmp(hjh x,hjh y){
	return x.my<y.my;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	double n;cin>>t;
	long long ans=0;
	while(t--){
		cin>>n;int m[5]={0};
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>j1[i].my>>j2[i].my>>j3[i].my;
			m
		}
		sort(j1+1,j1+1+n,cmp);sort(j2+1,j2+1+n,cmp);
		sort(j3+1,j3+1+n,cmp);
		for(int i=n;i>0;i--){
			if(j1[i].my>j2[i].my&&j1[i].my>j3[i].my){
				j1[i].zx=1;
			}
		}
	}
	return 0;
}
