#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N],x[N][N];
struct stu{
	int l,r;
}b[N*N];
bool cmp(stu &x,stu &y){
	if(x.r==y.r){
		return x.l<y.l;
	}
	else{
		return x.r<y.r;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		x[i][i]=a[i];
		for(int j=i+1;j<=n;j++){
			x[i][j]=x[i][j-1]^a[j];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			cout<<x[i][j]<<" ";
//		}
//		cout<<endl;
//	}
    int cnt=0;
    for(int i=1;i<=n;i++){
    	for(int j=i;j<=n;j++){
    		if(x[i][j]==k){
    			b[++cnt].l=i;
    			b[cnt].r=j;
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	int ans=0,pre=0;
	for(int i=1;i<=cnt;i++){
		if(b[i].l>pre){
			ans++;
			pre=b[i].r;
		}
	}
	printf("%d",ans);
	return 0;
}
