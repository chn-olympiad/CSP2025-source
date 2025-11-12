#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,ans;
int a[N];
bool vis[N];
struct node{
	int l,r;
}b[N];
bool ch(int x,int num){
	for(int i=x;i<=x+num;i++){
		if(vis[i]){
			return false;
		}
	}
	int res=a[x];
	for(int i=x+1;i<=x+num;i++){
		res^=a[i];
	}
	if(res==k){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=true;
	bool flag2=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
		if(a[i]>1) flag2=false;
	}
	if(k==0&&flag){
		cout<<(n/2);
		return 0;
	}else if(k<=1&&flag2){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;	
			}
		}
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
					vis[i]=true;
				}
				if(a[i]==1&&a[i+1]==1&&vis[i]!=true&&vis[i+1]!=true){
					ans++;
					vis[i]=vis[i+1]=1;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	int tot=1;
	b[1].l=1;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			vis[i]=true;
			tot++;
			b[tot].l=i+1;
		}
		if(!vis[i]){
			b[tot].r=i;
		}
	}
	for(int i=1;i<=tot;i++){
		int num=1;
		while(b[i].l<b[i].r){
			if(num>b[i].r-b[i].l){
				break;
			}
			int l=b[i].l,r=b[i].r;
			for(int j=l;j<=r;j++){
				if(ch(j,num)){
					b[++tot].l=j+num+1;
					b[tot].r=b[i].r;
					b[i].r=j+num;
					ans++;
					for(int o=j;o<=j+num;o++){
						vis[o]=true;
					}
				}
			}
			num++;
		}
	}
	cout<<ans;
	return 0;
}
