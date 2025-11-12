#include<bits/stdc++.h>
using namespace std;
long long n,m,a,num,ans,mp[105][105],sum;
vector<long long> ve;
bool cmd(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a;
		if(i==1){
			num=a;
		}
		ve.push_back(a);
	}
	sort(ve.begin(),ve.end(),cmd);
	for(long long i=0;i<ve.size();i++){
		if(ve[i]==num){
			ans=i+1;
		}
	}
	int j=1;
	for(int i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			mp[i][j]=ve[sum];
			if(ve[sum]==num){
				cout<<i<<" "<<j;
				return 0;
			}
			sum++;
		}
		i++;
		if(i>m)break;
		for(j=n;j>=1;j--){
			mp[i][j]=ve[sum];
			if(ve[sum]==num){
				cout<<i<<" "<<j;
				return 0;
			}
			sum++;
		}
	}
}
