#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],s[N],n,k,ans;
struct qujian{
	int l,r;
}area[N];
int p;
bool cmp(qujian x,qujian y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) s[i]=s[i-1] xor a[i];
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++){
		if((s[j] xor s[i-1])==k) area[++p].l=i, area[p].r=j;
	}
	sort(area+1,area+p+1,cmp);
	int sd=1;
	for(int i=1;i<=p;i++){
		if(area[i].l>=sd) sd=area[i].r+1, ans++;
	}
	printf("%d\n",ans);
	return 0;
}