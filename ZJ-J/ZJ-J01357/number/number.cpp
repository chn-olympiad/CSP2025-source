#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010],al=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++al]=s[i];
		}
	}
	sort(a+1,a+1+al);
	for(int i=al;i>=1;i--)
		putchar(a[i]);
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int a[1000010],p[4000010],q,t1[4000010],t2[4000010],n,mo;
void jianshu(int l,int r,int xb){t1[xb]=1,t2[xb]=0;if(l==r)p[xb]=a[l]%mo;else jianshu(l,l+r>>1,xb*2),jianshu((l+r>>1)+1,r,xb*2+1),p[xb]=p[xb*2]+p[xb*2+1],p[xb]%=mo;}
void doescheng(int xb,int sz){t1[xb]*=sz,t2[xb]*=sz,p[xb]*=sz;t1[xb]%=mo,t2[xb]%=mo,p[xb]%=mo;}void doesadd(int xb,int sz){t2[xb]+=sz,p[xb]+=sz;t1[xb]%=mo,t2[xb]%=mo,p[xb]%=mo;}
void push_down(int xb){
	doescheng(xb*2,t1[xb]),doesadd(xb*2,t2[xb]);
	doescheng(xb*2+1,t1[xb]),doesadd(xb*2+1,t2[xb]);
	t1[xb]=1,t2[xb]=0;
}
void mul(int l,int r,int f,int e,int xb,int sz){
	if(l>=f&&r<=e){
		t1[xb]*=sz,t2[xb]*=sz,p[xb]*=sz;t1[xb]%=mo,t2[xb]%=mo,p[xb]%=mo;return;
	}
	push_down(xb);
	int mid=(l+r)/2;
	if(mid>=f)mul(l,mid,f,e,xb*2,sz);
	if(mid+1<=e)mul(mid+1,r,f,e,xb*2+1,sz);
	p[xb]=p[xb*2]+p[xb*2+1];t1[xb]%=mo,t2[xb]%=mo,p[xb]%=mo;
}
void add(int l,int r,int f,int e,int xb,int sz){	
	if(l>=f&&r<=e){
		t2[xb]+=sz,p[xb]+=sz;t1[xb]%=mo,t2[xb]%=mo,p[xb]%=mo;return;
	}
	push_down(xb);
	int mid=(l+r)/2;
	if(mid>=f)add(l,mid,f,e,xb*2,sz);
	if(mid+1<=e)add(mid+1,r,f,e,xb*2+1,sz);
	p[xb]=p[xb*2]+p[xb*2+1];t1[xb]%=mo,t2[xb]%=mo,p[xb]%=mo;
}
int query(int l,int r,int f,int e,int xb){	
	if(l>=f&&r<=e){
		return p[xb];
	}
	push_down(xb);
	int mid=(l+r)/2,ans=0;
	if(mid>=f)ans+=query(l,mid,f,e,xb*2);
	if(mid+1<=e)ans+=query(mid+1,r,f,e,xb*2+1);
	return ans%mo;
}
main(){
	cin>>n>>q>>mo;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	jianshu(1,n,1);
	while(q--){
		int opt;
		cin>>opt;
		if(opt==1){
			int f,e,sz;
			cin>>f>>e>>sz;
			mul(1,n,f,e,1,sz);
		}
		if(opt==2){
			int f,e,sz;
			cin>>f>>e>>sz;
			add(1,n,f,e,1,sz);
		}
		if(opt==3){
			int f,e;
			cin>>f>>e;
			cout<<query(1,n,f,e,1)<<'\n';
		}
	}
	return 0;
}
*/
