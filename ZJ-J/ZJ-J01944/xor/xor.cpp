#include<bits/stdc++.h>
using namespace std;
int a[1100000]={0};
bool b[1100000]={0};
	int ans=0;
	int n,k;
struct node{
	int u,v;
}c[1200000];
int p=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum;
	for(int i=1;i<=n;i++){
			sum=a[i];
			for(int j=i;j<=n;j++){
				if(sum==k){
					p++;
					c[p].u=i;
					c[p].v=j;
					break;
				}
				if(j<n) sum=sum^a[j+1];
			}
	}
	for(int i=1;i<=p;i++){
		for(int j=i+1;j<=p;j++){
			if(c[i].u<=c[j].u&&c[i].v>=c[j].v){
					c[i].u=-1;
					c[i].v=-1;
			}
		}
	}
	for(int i=1;i<=p;i++){
		if(c[i].u!=-1) ans++;
	}
	cout<<ans;
	return 0;
}
