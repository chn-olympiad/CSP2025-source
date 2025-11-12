#include<bits/stdc++.h>
using namespace std;
int a[10000010];
int cnt=0,maxn=-1;
pair<int,int> p[199000000];
int add(int n,int m){
	int sum=a[n];
	for(int i=n+1;i<=m;i++){
		sum=sum xor a[i];
	}
	return sum;
}
bool cmp(pair<int,int> p1,pair<int,int> p2){
	if(p1.first==p2.first){
		return p1.second<p2.second;
	}
	else{
		return p1.first<p2.first;
	}
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	int k;
	cin>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int m=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(add(i,j)==k){
				p[m].first=i;
				p[m].second=j;
				m++;
			}
		}
	}
	sort(p+1,p+m+1,cmp);
	k=1;
	for(int i=2;i<=m;i++){
		if(p[k].second<p[i].first){
			cnt++;
			k=i;
		}
	}
	cout<<cnt;
}
