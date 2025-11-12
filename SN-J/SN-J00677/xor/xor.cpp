//DuanChencheng's code
//number:SN-J00677
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int l,r,ans;
int n,k,a[500005],qz[500005];
pair<int,int> b[500005];
vector<pair<int,int>> qj; 
int findr(int x,int pos){
	int l=1,r=n,mid,res=0;
	while(l<=r){
		mid=(l+r)/2;
		if(b[mid].first==x&&b[mid].second>=pos){
			res=mid;
			r=mid-1;
		}else if(b[mid].first<x||(b[mid].first==x&&b[mid].second<pos)){
			l=mid+1;
		}else r=mid-1;
	}
	return b[res].second;
}
bool cmp(pair<int,int> x,pair<int,int> y){
	if(x.first==y.first)
	return x.second<y.second;
	else 
	return x.first<y.first; 
}
bool cmp2(pair<int,int> x,pair<int,int> y){
	if(x.second!=y.second) return x.second<y.second;
	else return x.first<y.first;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qz[i]=qz[i-1]^a[i]; 
		b[i].first=qz[i],b[i].second=i;
	}
	sort(b+1,b+n+1,cmp);
	for(int l=1;l<=n;l++){
		int valr=k^qz[l-1];
		int r=findr(valr,l);
		if((qz[r]^qz[l-1])==k&&r>=l){
			qj.push_back({l,r});
		}
	}
	sort(qj.begin(),qj.end(),cmp2); 
	int lst=-1,len=qj.size();
	for(int i=0;i<len;i++){
		if(lst<qj[i].first){
			lst=qj[i].second;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
