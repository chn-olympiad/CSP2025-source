#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
int n,m,k;
cin>>n>>m>>k;
vector<int> sum;
for(int i=0;i<n;i++){
int a,b,c;
cin>>a>>b>>c;
sum.push_back(c);
}int minin=100005;
for(int i=0;i<k;i++){int a[10005];
	for(int j=0;j<n;j++){
		int s;
		cin>>s;
		cin>>a[j];
		if(a[j]<minin){
			minin=a[j];
		}
	}
}sort(sum.begin(),sum.end());
long long ans=0;
if(k==0){
for(int i=0;i<sum.size()-1;i++){
	ans+=sum[i];
}cout<<ans;}else{
for(int i=0;i<sum.size()-2;i++){
	ans+=sum[i];
}	ans+=minin;
cout<<ans;
}

	return 0; 
} 
