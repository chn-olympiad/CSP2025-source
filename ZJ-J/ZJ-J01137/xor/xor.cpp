#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005]{0};
bool c[500005]{0};
struct aaa{
	int l,r;
};
bool cmp(aaa a,aaa b){
	if(a.r==b.r){
		return a.l>b.l;
	}
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<aaa> d;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		//cout<<b[i]<<" ";
	}
	//cout<<"\n";
	for(int i=0;i<n;i++){
		for(int j=1;j+i<=n;j++){
			if((b[j+i]^b[j-1])==k){
				//cout<<j<<" "<<j+i<<"\n";
				d.push_back({j,i+j});
				//ans++;
			}
			//cout<<j<<" "<<j+i<<" "<<sum<<"\n";
		}
	}
	sort(d.begin(),d.end(),cmp);
	int l=0;
	for(int i=0;i<d.size();i++){
		if(d[i].l>l){
			ans++;
			l=d[i].r;
		}
	}
	
	cout<<ans;
	return 0;
}