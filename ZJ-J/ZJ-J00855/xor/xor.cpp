#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,top;
int a[500002];	//数组开小 
bool flag[500002];
struct node2{
	int l,r,len;
}id[500002];
struct node{
	int val;
}seg[500002];
bool cmp(const node2 &x,const node2 &y){
	if(x.len!=y.len)	return x.len<y.len;
	return x.l<y.l;
}
void update(int id){
	seg[id].val=seg[id<<1].val^seg[id<<1|1].val;
}
void build(int id,int l,int r){
	if(l==r){
		seg[id].val=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
//	printf("%d %d\n",id,seg[id].val);
}
int query(int id,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return seg[id].val;
	int mid=(l+r)>>1;
	if(mid>=qr)	return query(id<<1,l,mid,ql,qr);
	else if(mid<ql)	return query(id<<1|1,mid+1,r,ql,qr);
	else 	return query(id<<1,l,mid,ql,qr)^query(id<<1|1,mid+1,r,ql,qr);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(k==0){
		int sum=0;
		for(int i=1;i<=n;i++)
			if(a[i]!=1)	goto nxt;
		printf("0\n");
		return 0;
		nxt:;
		for(int i=1;i<=n;i++)
			if(a[i]>1)	goto xp;
		for(int i=1;i<=n;i++)
			if(a[i]==0)
				sum++;
		printf("%d\n",sum);
		return 0;
	}else if(k==1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)	sum++;
			if(a[i]>1)	goto xp; 
		}
		printf("%d\n",sum);
		return 0;
	}
	xp:
//	printf("%d",ans);
	if(n>5000){
		for(int i=1;i<=n;i++)
		if(a[i]==k)	ans++;
		printf("%d\n",ans);
		return 0;
	}
	build(1,1,n);
	for(int len=1;len<=n;len++)
		for(int l=1,r=len+l-1;r<=n;l++,r++){
			int cnt=query(1,1,n,l,r);
//			printf("%d\n",cnt);
			if(cnt==k)
				id[++top].l=l,id[top].r=r,id[top].len=r-l+1;
		}
	sort(id+1,id+top+1,cmp);
//	printf("%d\n",top);
	for(int i=1;i<=top;i++){
		for(int j=id[i].l;j<=id[i].r;j++){
			if(flag[j]){
				printf("%d",ans);
				return 0;
			}
			flag[j]=true;
		}
		ans++;
	}
	printf("%d",ans);
	return 0;
}
//n^2：枚举左端点，往右贪心找最多 
