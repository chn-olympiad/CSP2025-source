#include<bits/stdc++.h>
using namespace std;
int n,top;
char s[1000002];
int a[1000002];
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	//评测大样例 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9'){
	 		a[++top]=s[i]-'0';
		}
	sort(a+1,a+top+1,cmp);
	for(int i=1;i<=top;i++)
		printf("%d",a[i]);
	return 0;
}
/*
线段树是神 
#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int val,t,si;
}seg[500002];
void update(int id){
	seg[id].val=seg[id<<1].val^seg[id<<1|1].val;
}
void build(int id,int l,int r){
	seg[id].si=r-l+1;
	if(l==r){
		seg[id].val=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}
void settag(int id,int t){
	seg[id].t+=t;
	seg[id].val+=t*si;
}
void pushdown(int id){
	if(seg[id].t){
		settag(id<<1,seg[id].t);
		settag(id<<1|1,seg[id].t);
		seg[id].t=0;
	}
}
void modify(int id,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		settag(id);
		return;
	}
	pushdown(id);
	int mid=(l+r)>>1;
	if(mid>=qr)
		modify(id<<1,l,mid,ql,qr);
	else if(mid<ql)
		modify(id<<1|1,mid+1,r,ql,qr);
	else{
		modify(id<<1,l,mid,ql,qr);
		modify(id<<1|1,mid+1,r,ql,qr);
	}
	update(id);
}
int query(int id,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return seg[id].val;
	pushdown(id);
	int mid=(l+r)>>1;
	if(mid>=qr)
		return query(id<<1,l,mid,ql,qr);
	else if(mid<ql)
		return query(id<<1|1,mid+1,r,ql,qr);
	else
		return query(id<<1,l,mid,ql,qr)^query(id<<1|1,mid+1,r,ql,qr);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	while(m--){
		int op,l,r,val;
		scanf("%d",&op);
		if(op==1){
			//区间修改 
			scanf("%d%d%d",&l,&r,&val);
			modify(1,1,n,l,r,val);
		}else if(op==2){
			//区间查询
			scanf("%d%d",&l,&r);
			printf("%d\n",query(1,1,n,l,r)); 
		}
	}
	return 0;
}
//洛谷：【模版】线段树1 
//来自：喜欢编程的杨同学（抖音） 
*/
