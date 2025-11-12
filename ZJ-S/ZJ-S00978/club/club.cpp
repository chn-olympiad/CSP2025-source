#include<bits/stdc++.h>
#define ll long long
#define inf64 (ll)0x3f3f3f3f3f3f3f3f
#define inf32 (int)0x3f3f3f3f
#define _inf32 (int)0xc0c0c0c0
#define _inf64 (ll)0xc0c0c0c0c0c0c0c0
#define N 100010
inline int in(){
	int sum=0,op=0,c=getchar();
	while(c<48||57<c)op=(c=='-'?0:1),c=getchar();
	while(48<=c&&c<=57)sum=(sum<<3)+(sum<<1)+c-48,c=getchar();
	return op?(~sum)+1:sum;
}
using namespace std;
int t,n,n2;
int cmp[N];
int a[N][5],maxa[N];
vector<int> lis[5];
ll sum=0;
int main(){
//	freopen("club5.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=in();
	while(t--){
		sum=0;
		lis[1].clear();
		lis[2].clear();
		lis[3].clear();
		n=in(),n2=n>>1;
		for(int i=1;i<=n;i++){
			a[i][1]=in(),a[i][2]=in(),a[i][3]=in();
			maxa[i]=max(a[i][1],max(a[i][2],a[i][3]));
			sum+=maxa[i];
			if(maxa[i]==a[i][1]){
				sort(a[i]+1,a[i]+4);
				cmp[i]=a[i][3]-a[i][2];
				lis[1].push_back(cmp[i]);
			}else if(maxa[i]==a[i][2]){
				sort(a[i]+1,a[i]+4);
				cmp[i]=a[i][3]-a[i][2];
				lis[2].push_back(cmp[i]);
			}else{
				sort(a[i]+1,a[i]+4);
				cmp[i]=a[i][3]-a[i][2];
				lis[3].push_back(cmp[i]);
			}
		}
		for(int i=1;i<=3;i++){
			if(lis[i].size()>n2){
				sort(lis[i].begin(),lis[i].end());
				int len=lis[i].size()-n2;
				for(int j=0;j<len;j++){
					sum-=lis[i][j];
				}
			}
		}
		printf("%lld\n",sum);
	}
//	freopen("chk.out","w",stdout);
//	system("fc club.out club5.ans");
}