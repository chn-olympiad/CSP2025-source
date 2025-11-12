#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=5e5+114;
int n,k;
int a[N];
int s[N];
struct node{
	int l,r;
};
vector<node>p;
bool cmp(node x,node y){
	if(x.r!=y.r)return x.r<y.r;
	else return x.l>y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
//		cout<<s[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==k){
//				cout<<i<<" "<<j<<"\n";
				p.push_back({i,j});
			}
		}
	}
	sort(p.begin(),p.end(),cmp);
	int x=0,ans=0;
	for(int i=0;i<p.size();i++){
//		cout<<p[i].l<<" "<<p[i].r<<"\n";
		if(p[i].l>x){
			x=p[i].r;
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

