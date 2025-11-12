#include<bits/stdc++.h>
using namespace std;
const int N=5000010;
long long s[N][10];
int lena=0,lenb=0,lenc=0;
struct node{
	long long id,val;
}a[N],b[N],c[N];
int cmp1(node a,node b){
	return a.val-max(s[a.id][2],s[a.id][3])>b.val-max(s[b.id][2],s[b.id][3]);
}
int cmp2(node a,node b){
	return a.val-max(s[a.id][1],s[a.id][3])>b.val-max(s[b.id][1],s[b.id][3]);
}
int cmp3(node a,node b){
	return a.val-max(s[a.id][1],s[a.id][2])>b.val-max(s[b.id][1],s[b.id][2]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q;
	cin>>q;
	while(q--){
		int n;
		scanf("%d",&n);
		lena=0,lenb=0,lenc=0;
		long long cnt=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&s[i][1],&s[i][2],&s[i][3]);
			if(s[i][1]>=max(s[i][2],s[i][3]))
				a[++lena].id=i,a[lena].val=s[i][1];
			else if(s[i][2]>=max(s[i][1],s[i][3]))
				b[++lenb].id=i,b[lenb].val=s[i][2];
			else
				c[++lenc].id=i,c[lenc].val=s[i][3];
		}
		sort(a+1,a+1+lena,cmp1);
		if(lena>n/2){
			for(int i=n/2+1;i<=lena;i++){
				if(s[a[i].id][2]>=s[a[i].id][3]){
					if(lenb<n/2)
						b[++lenb].id=a[i].id,b[lenb].val=s[a[i].id][2];
					else
						c[++lenc].id=a[i].id,c[lenc].val=s[a[i].id][3];
				}
				else{
					if(lenc<n/2)
						c[++lenc].id=a[i].id,c[lenc].val=s[a[i].id][3];
					else
						b[++lenb].id=a[i].id,b[lenb].val=s[a[i].id][2];
				}
			}
			lena=n/2;
		}
		sort(b+1,b+1+lenb,cmp2);
		if(lenb>n/2){
			for(int i=n/2+1;i<=lenb;i++){
				if(s[b[i].id][1]>=s[b[i].id][3]){
					if(lena<n/2)
						a[++lena].id=b[i].id,a[lena].val=s[b[i].id][1];
					else
						c[++lenc].id=b[i].id,c[lenc].val=s[b[i].id][3];
				}
				else{
					if(lenc<n/2)
						c[++lenc].id=b[i].id,c[lenc].val=s[b[i].id][3];
					else
						a[++lena].id=b[i].id,a[lena].val=s[b[i].id][1];
				}
			}
			lenb=n/2;
		}
		sort(c+1,c+1+lenc,cmp3);
		if(lenc>n/2){
			for(int i=n/2+1;i<=lenc;i++){
				if(s[c[i].id][1]>=s[c[i].id][2]){
					if(lena<n/2)
						a[++lena].id=c[i].id,a[lena].val=s[c[i].id][1];
					else
						b[++lenb].id=c[i].id,b[lenb].val=s[c[i].id][2];
				}
				else{
					if(lenb<n/2)
						b[++lenb].id=c[i].id,b[lenb].val=s[c[i].id][2];
					else
						a[++lena].id=c[i].id,a[lena].val=s[c[i].id][1];
				}
			}
			lenc=n/2;
		}
		for(int i=1;i<=lena;i++)
			cnt+=a[i].val;
		for(int i=1;i<=lenb;i++)
			cnt+=b[i].val;
		for(int i=1;i<=lenc;i++)
			cnt+=c[i].val;
		printf("%lld\n",cnt);
	}
	return 0;
}
