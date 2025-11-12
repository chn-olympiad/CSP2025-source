#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct Node{
	int l,r;
	bool operator <(const Node x)const{
		if(r==x.r)return l<x.l;
		return r<x.r;
	}
}e[N]; 
int n,tot;
long long a[N],s[N];
long long k;
vector<long long> t[N]; 
//map<long long,pair<int,int> > mp;
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	t[0].push_back(0);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=(s[i-1]^a[i]);
		t[s[i]].push_back(i);
//		st.insert({s[i],i});
	}
//	for(int d=1;d<=n;d++){
//		for(int i=1;i<=n-d+1;i++){
//			int j=i+d-1;
//			if((s[j]^s[i-1])==k){
//				e[++tot].l=i,e[tot].r=j;
//			}
//		}
//	}
	for(int i=n;i>=1;i--){
		int x=(s[i]^k);
		for(auto j:t[x]){
			if(j<i){
				e[++tot].l=j+1;
				e[tot].r=i;
			}
		}
	}
//	for(int i=1;i<=n;i++)cout<<s[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=n;i++)cout<<(s[i]^5)<<" ";
//	cout<<endl;
//	for(int i=1;i<=tot;i++)
//		cout<<e[i].l<<" "<<e[i].r<<endl;
	sort(e+1,e+1+tot);
	int R=e[1].r,ret=1;
	for(int i=2;i<=tot;i++){
		if(e[i].l>R){
			R=e[i].r;
			ret++;
		}
	}
	printf("%d\n",ret);
	return 0;
}
