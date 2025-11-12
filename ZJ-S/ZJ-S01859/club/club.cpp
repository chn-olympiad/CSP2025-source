#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define VE vector
LL n,t,ans;struct c{LL v,r,ii;};
LL cmp(c a,c b){return a.v>b.v;}
void ad(unordered_set<LL>&vi,VE<LL>&z,LL vvv,LL rrr,LL ia){
	vi.insert(ia);z[rrr]++;ans+=vvv;
}
void wo(){
	unordered_set<LL>vi;ans=0;
	cin>>n;VE<VE<LL>>ar(n,VE<LL>(3)),ar2(3,VE<LL>(n));VE<c>tm;VE<LL>z(3);
	for(LL i=0;i<n;i++){
		cin>>ar[i][0]>>ar[i][1]>>ar[i][2];
		tm.push_back({ar[i][0],0,i});
		tm.push_back({ar[i][1],1,i});tm.push_back({ar[i][2],2,i});
	}
	sort(tm.begin(),tm.end(),cmp);
	for(LL j=0;j<tm.size();j++){
		if(vi.size()==n)break;
		const auto[vv,rr,i]=tm[j];
		if(vi.count(i)||z[rr]>=n/2){
			for(LL k=j+1;k<tm.size();k++){
				const auto[vvv,rrr,ia]=tm[j];
				if(!vi.count(ia)&&z[rrr]<n/2)
				{ad(vi,z,vvv,rrr,ia);j=k;break;}
			}
		}else{
			ad(vi,z,vv,rr,i);
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		wo();
	}
	return 0;
}
