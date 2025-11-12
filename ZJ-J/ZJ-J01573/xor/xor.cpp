#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
struct qj{
	int l,r;
};
vector<qj>v;
bool cmp(qj p,qj q){
	return p.r<q.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >>n>>k;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}for(int x=1;x<=n;x++){
		int num=a[1];
		if(x==1){
			if(num==k){
				v.push_back({1,1});
			}
		}else{
			for(int i=2;i<=x;i++){
				num^=a[i];
			}if(num==k){
				v.push_back({1,x});
			}
		}
		for(int i=2;i<=n-x+1;i++){
			int j=i+x-1;
			num^=a[i-1];
			num^=a[j];
			if(num==k){
				v.push_back({i,j});
			}
		}
	}sort(v.begin(),v.end(),cmp);
	int tail=0;
	int cnt=0;
	for(int i=0;i<v.size();i++){
		if(v[i].l>tail){
			tail=v[i].r;
			cnt++;
		}
	}cout <<cnt;
	return 0;
}

