#include <bits/stdc++.h>
using namespace std;
struct Node{
	long long l,r,p;
}t[5000010];
bool cmp(Node a,Node b){
	if(a.p!=b.p)return a.p<b.p;
	if(a.l!=b.l)return a.l<b.l;
	return a.r<b.r;
}
long long n,m,k,a[5000010],s[5000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((s[i]^s[j-1])==k){
				//cout<<i<<" "<<j<<" "<<(s[i]^s[j-1])<<"\n";
				m++;
				t[m].l=j,t[m].r=i;
				t[m].p=t[m].r-t[m].l+1;
				//cout<<t[m].l<<" "<<t[m].r<<" "<<t[m].p<<"\n";
			}
		}
	}
	sort(t+1,t+1+m,cmp);
	long long ed=0,ans=0;
	for(int i=1;i<=m;i++){
		//cout<<t[i].l<<" "<<t[i].r<<" "<<t[i].p<<"\n";
		if(t[i].l>ed){
			ed=t[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}