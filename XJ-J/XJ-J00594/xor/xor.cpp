#include<bits/stdc++.h>
using namespace std;
int a[500003],m=0;
struct node{//区间数组 
	int l,r;
}b[500003];
bool cmp(node a,node b){//贪心排序 
	if(a.r==b.r)return a.l>b.l;
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);//文件输入输出 
	int n,t;
	scanf("%d",&n);
	scanf("%d",&t);
	for(int i=1;i<=n;i++){//前缀和（异或两个相同的数等于不异或） 
		scanf("%lld",&a[i]);
		a[i]=a[i]^a[i-1];
	}
	for(int i=1;i<=n;i++){//查找成立区间 
		for(int j=i;j<=n;j++){
			if((a[j]^a[i-1])==t){
				b[m].l=i;//标记 
				b[m].r=j;
				m++;
			}
		}
	}
	sort(b,b+m,cmp);//排序 
	int s=1;
	int ma=b[0].r;
	for(int i=1;i<m;i++){//贪心查找 
		if(b[i].l>ma){
			s++;
			ma=b[i].r;
		}
	}
	cout<<s;
	return 0;
} 
