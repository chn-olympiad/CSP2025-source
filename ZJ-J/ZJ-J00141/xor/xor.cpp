#include<bits/stdc++.h>
using namespace std;
//bool cmp(pair<int,int>x,pair<int,int>y){
//	if(x.first!=y.first)return x.first<y.first;
//	return x.second<y.second;
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	long long n,k;
	cin>>n>>k;
	long long a[n+2];
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<pair<int,int>>pairs;
	int lastEnd=-1;
	int sum=0;
	for(int i=1;i<=n;i++){
		long long result=0;
		lastEnd=-1;
		for(int j=i;j<=n;j++){
			result=(result^a[j]);
			if(result==k){
				pairs.push_back({i,j});
				sum++;
				lastEnd=j;
				break;
			}	
		}
		if(lastEnd!=-1)i=lastEnd;
	}
//	sort(pairs.begin(),pairs.end(),cmp);
//	int sum=0;
//	lastEnd=0;
//	for(int i=0;i<pairs.size();i++){
//		if(pairs[i].first>lastEnd){
//			sum++;
//			lastEnd=pairs[i].second;
//		}
//	}
	cout<<sum;
	
	return 0;
}