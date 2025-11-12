#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
namespace Subtask1{//60pts
	int f[5005][5005],tot,ans;
	struct node{
		int l,r;
	}e[25000005];
	inline bool cmp(node x,node y){
		return x.r<y.r;
	}
	signed main(){
		for(int i=1;i<=n;i++){
			f[i][i]=a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				f[i][j]=f[i][j-1]^a[j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(f[i][j]==k){
					e[++tot].l=i;
					e[tot].r=j;
				}
			}
		}
		sort(e+1,e+1+tot,cmp);
		int lst=0;
		for(int i=1;i<=tot;i++){
			if(e[i].l>lst){
				ans++;
				lst=e[i].r;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
};
int tot;
struct node{	
	int l,r;
}e[25000005];
inline bool cmp(node x,node y){
	return x.r<y.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){//5pts
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[i-1]==1){
				e[++tot].l=i-1;
				e[tot].r=i;
			}
		}
		sort(e+1,e+1+tot,cmp);
		int lst=0;
		for(int i=1;i<=tot;i++){
			if(e[i].l>lst){
				ans++;
				lst=e[i].r;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	Subtask1::main();
	return 0;
}
