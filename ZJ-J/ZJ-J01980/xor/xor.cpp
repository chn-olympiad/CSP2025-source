#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],b[500010],kk,h,ans,hyk;
pair<long long,long long> x[500010];
bool cmp(pair<long long,long long> xx,pair<long long,long long> yy){
	return xx.second<yy.second;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long y;
			if(j==i){
				y=b[i];
			}
			else{
				y=b[j]^b[i-1];
			}
			if(y==k){
				kk+=1;
				x[kk]={i,j};
			}
		}
	}
	sort(x+1,x+kk+1,cmp);
	for(int i=1;i<=kk;i++){
		if(x[i].first>h){
			ans++;
			h=x[i].second;
		}
	}
	cout<<ans;
	return 0;
}

