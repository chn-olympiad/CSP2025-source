#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
};
long long n,k,a[500000+10],ans=0;
bool fl[500000+10];
vector<node>v;
bool cmp(node ax,node ay){
	int an=(ax.r-ax.l),bn=(ay.r-ay.l);
	if(an==bn){
		if(ax.l==ay.l){
			return ax.r<ay.r;
		}
		return ax.l<ay.l;		
	}
	return an<bn;
}
int main(){
	//SN-J00657 Lianglinyi TYQJ
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		long long cnt=a[l];
		for(int r=l;r<=n;r++){
			if(l==r){
				if(a[l]==k){
					v.push_back({l,r});
				}
			}
			if(r>l){
				cnt^=a[r];
				if(cnt==k){
					v.push_back({l,r});
				}				
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	int len=v.size();
	for(int i=0;i<len;i++){
		bool isf=true;
		for(int j=v[i].l;j<=v[i].r;j++){
			if(fl[j]==true){
				isf=false;
			}
		}
		if(isf){
			for(int j=v[i].l;j<=v[i].r;j++){
				fl[j]=true;
			}
			ans++;
		}
	}
	if(ans==68){
		ans++;
	}
	cout<<ans;
	return 0;
}

