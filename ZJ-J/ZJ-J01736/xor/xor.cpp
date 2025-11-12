#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans,s[500100],cnt;
struct Node{
	int l,r;
}e[1000100];
int cmp(Node x,Node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	if(n<=10000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((s[j]^s[i-1])==k)e[++cnt].l=i,e[cnt].r=j;
			}
		}
		sort(e+1,e+cnt+1,cmp);
		int right=0;
		for(int i=1;i<=cnt;i++){
			if(e[i].l>right)ans++,right=e[i].r;
		}
		cout<<ans;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			if(a[i]==1&&a[i-1]==1)ans++,i++;
		}
		cout<<ans;
	}else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		cout<<ans;
	}else{
		return 0;
	}
	return 0;
}
