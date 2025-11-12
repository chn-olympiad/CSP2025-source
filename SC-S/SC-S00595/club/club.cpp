#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
pair<int,pair<int,int> > a[N+10],b[N+10];

bool cmp1(pair<int,pair<int,int> > x,pair<int,pair<int,int> > y){
	return x.first>y.first;
}
bool cmp2(pair<int,pair<int,int> > x,pair<int,pair<int,int> > y){
	return x.second.first>y.second.first;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second.first>>a[i].second.second;
		memcpy(a,b,sizeof(a));
		sort(a+1,a+n+1,cmp1);
		sort(b+1,b+n+1,cmp2);
		int cnt=0;
		for(int i=1;i<=n/2;i++)cnt+=a[i].first+b[i].second.first;
		cout<<cnt;
	}

	fclose(stdin);fclose(stdout);
	return 0;
}