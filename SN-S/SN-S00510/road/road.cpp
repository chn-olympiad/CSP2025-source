#include<iostream>
#include<algorithm>
using namespace std;
struct City{
	long long be,ed,pay;
};
City c[1000010];
bool cmp(const City &a,const City &b){
	return a.pay<b.pay;
}
int cnt[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		cin>>c[i].be>>c[i].ed>>c[i].pay;
	}
	long long pa;
	for(long long i=1+m;i<=m+k;i++){
		cin>>pa;
		for(long long j=1+m;j<=m*2;j++){
			cin>>c[j].pay;
			c[j].pay+=pa;
			c[j].be=j-m;
			c[j].ed=i;
		}	
	}
	sort(c+1,c+m*2+1,cmp);
	long long tot=0;
	for(long long i=1;i<=m*2;i++){
		if(cnt[c[i].be]==0||cnt[c[i].ed]==0) {
			tot+=c[i].pay;
			cnt[c[i].be]++;
			cnt[c[i].ed]++;
			cout<<tot<<endl;
		}
		else break;
	}
	cout<<tot;
	return 0;
}
