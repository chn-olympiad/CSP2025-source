#include <bits/stdc++.h>
using namespace std;
int aaa=0,bbb=0,ccc=0;
struct xx{
	int a,b,c;
}arr[10000005];
struct xxx{
	int jz,bh,ys,bj,zs;
}brr[10000005];
bool cmp(xxx x,xxx y){
	return x.jz>y.jz;
}
int vis[10000005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	while(t--){
		int n;
		cin >>n;
		for(int i=1;i<=n+10000;i++){
			arr[i].a=0;
			arr[i].b=0;
			arr[i].c=0;
		}
		for(int i=1;i<=n*4;i++){
			brr[i].jz=0;
			brr[i].bh=0;
		}
		for(int i=1;i<=n*4;i++){
			vis[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin >>arr[i].a>>arr[i].b>>arr[i].c;
		}
		int aa=n/2;
		int bb=n/2;
		int cc=n/2;
		int len=0;
	    aaa=0,bbb=0,ccc=0;
		for(int i=1;i<=n;i++){
			brr[++len].jz=(arr[i].a-arr[i].b)+(arr[i].a-arr[i].c);
			brr[len].bh=1;
			brr[len].ys=arr[i].a;
			brr[len].bj=i;
			aaa+=arr[i].a;
		}
		for(int i=1;i<=n;i++){
			brr[++len].jz=(arr[i].b-arr[i].a)+(arr[i].b-arr[i].c);
			brr[len].bh=2;
			brr[len].ys=arr[i].b;
			brr[len].bj=i;
			bbb+=arr[i].b;
		}
		for(int i=1;i<=n;i++){
			brr[++len].jz=(arr[i].c-arr[i].b)+(arr[i].c-arr[i].a);
			brr[len].bh=3;
			brr[len].ys=arr[i].c;
			brr[len].bj=i;
			ccc+=arr[i].c;
		}
		len=0;
		for(int i=1;i<=n;i++){
			brr[++len].zs=aaa;
		}
		for(int i=1;i<=n;i++){
			brr[++len].zs=bbb;
		}
		for(int i=1;i<=n;i++){
			brr[++len].zs=ccc;
		}
		sort(brr+1,brr+1+len,cmp);
		int ans=0;
		int x=0;
		for(int i=1;i<=n;i++){
			if(brr[i+x].bh==1&&aa>0&&vis[brr[i+x].bj]==0){
				ans+=brr[i+x].ys;
				aa--;
				vis[brr[i+x].bj]=1;
			}else if(brr[i+x].bh==2&&bb>0&&vis[brr[i+x].bj]==0){
				ans+=brr[i+x].ys;
				bb--;
				vis[brr[i+x].bj]=1;
			}else if(brr[i+x].bh==3&&cc>0&&vis[brr[i+x].bj]==0){
				ans+=brr[i+x].ys;
				cc--;
				vis[brr[i+x].bj]=1;
			}else{
				i--;
				x++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
