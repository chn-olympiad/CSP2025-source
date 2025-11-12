#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5;
int n,k,res,cnt;
int cover[N];
int num[N];
int num2[N];
bool sum[N][25];
struct Pair{
	int l,r;
}p[N];
//bool vis[N];
bool check(int l,int r){
	int s=0;
	for(int i=1;i<=20;++i) s+=pow(2,i-1)*(sum[r][i]^sum[l-1][i]);
	return (s==k);
}
//int get_res(int st){
//	printf("st:%d\n",st);
//	int pos=st,sum=0;
//	while(pos<=n){
//		if(vis[pos]){
//			++pos;
//			if(pos>n) break;
//		}
//		bool flag=false;
//		for(int i=pos;i<=n;++i){
//			if(check(pos,i)){
//				printf("%d %d\n",pos,i);
//				vis[pos]=true;
//				flag=true;
//				++sum;
//				pos=i;
//				break;
//			}
//		}
//		if(!flag) vis[pos]=true;
//		++pos;
//	}
//	return sum;
//}
void invit(void){
	int l=1,r=2;
	while(r<=cnt){
		if(p[r].l<=p[l].r){
			--res;
			if(cover[r]>=cover[l]){
				--cover[l];
				++r;
			}
			else l=r,++r;
		}
		else l=r,++r;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&num[i]);
		num2[i]=num[i];
	}
	for(int i=1;i<=20;++i){
		for(int j=1;j<=n;++j) sum[j][i]=sum[j-1][i]^(num2[j]%2);
		for(int j=1;j<=n;++j) num2[j]/=2;
	}
//	for(int i=1;i<=20;++i){
//		for(int j=1;j<=n;++j) printf("%d ",sum[j][i]);
//		putchar('\n');
//	}
//	for(int i=1;i<=n;++i)
//		if(!vis[i])	res=max(get_res(i),res);
//	for(int i=1;i<=n;++i){
//		int debug=get_res(i);
//		res=max(debug,res);
//		if(i<=100) printf("%d\n",debug);
//	}
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j){
			if(check(i,j)){
				p[++cnt].l=i,p[cnt].r=j;
				break;
			}
		}
	for(int i=1;i<=cnt;++i)
		for(int j=cnt;j>i;--j) if(p[j].l<=p[i].r) cover[i]=j-i;
	res=cnt;
	invit();
	printf("%d",res);
	return 0; 
}