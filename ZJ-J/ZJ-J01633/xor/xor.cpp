#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,vis[500005];
struct node{
	int l;
	int r;
}s[500005];
bool cmp(node a,node b){
	return a.r-a.l<b.r-b.l;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			vis[i]=1;
		}
	} 
	int id=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int sum=a[i];
			for(int q=i+1;q<=j;q++){
				sum^=a[q];
			}
			if(sum==k){
				s[id].l=i;
				s[id].r=j;
				id++;
				i++;
				j=i;
			}
		}
	}
	sort(s+1,s+id,cmp);
	for(int i=1;i<id;i++){
		int f=0;
		for(int j=s[i].l;j<=s[i].r;j++)
			if(vis[j]){
				f=1;
				break;
			}
		if(f) continue;
		ans++;
		for(int j=s[i].l;j<=s[i].r;j++){
			vis[j]=1;
		}	
	}
	cout<<ans;
	return 0;
}
