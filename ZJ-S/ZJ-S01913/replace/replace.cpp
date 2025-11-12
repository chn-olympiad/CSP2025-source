#include<bits/stdc++.h>
using namespace std;
int n,q,l1,l2,ne[5000005],ans[200005];
unsigned long long p=131,cm[5000005],hx1[5000005],hx2[5000005],hx3[5000005],hx4[5000005];
struct hh{
	string a,b;
	int l;
}a[200005],b[200005];
unsigned long long get1(int l,int r){
	return hx1[r]-hx1[l-1]*cm[(r-l+1)];
}
unsigned long long get2(int l,int r){
	return hx2[r]-hx2[l-1]*cm[(r-l+1)];
}
unsigned long long get3(int l,int r){
	return hx3[r]-hx3[l-1]*cm[(r-l+1)];
}
unsigned long long get4(int l,int r){
	return hx4[r]-hx4[l-1]*cm[(r-l+1)];
}
int ch(int x,int y,int l,int r){
	unsigned long long op1=get3(1,l-1)*cm[(b[x].l-l+1)]+get2(1,a[y].l)*cm[(b[x].l-r)]+get3(r+1,b[x].l),
					   op2=get4(1,b[x].l);
	return op1==op2;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		cin>>a[i].a>>a[i].b;
		a[i].l=a[i].a.size();
		l1+=a[i].a.size()+a[i].b.size();
		a[i].a=' '+a[i].a;
		a[i].b=' '+a[i].b;
	}
	for(int i=1;i<=q;++i){
		cin>>b[i].a>>b[i].b;
		b[i].l=b[i].a.size();
		l2+=b[i].a.size()+b[i].b.size();
		b[i].a=' '+b[i].a;
		b[i].b=' '+b[i].b;
	}
	cm[0]=1;
	for(int i=1;i<=5000000;i++){
		cm[i]=cm[i-1]*p;
	}
	for(int j=1;j<=n;++j){
		ne[1]=1;
		for(int i=2,o=0;i<=a[j].l;i++){
			if(o>0&&a[j].a[i]!=a[j].a[o+1]){
				o=ne[o];
			}
			if(a[j].a[i]==a[j].a[o+1]){
				o++;
			}
			ne[i]=o;
		}
		for(int i=1;i<=a[j].l;i++){
			hx1[i]=hx1[i-1]*p+(a[j].a[i]-'a'+1);
			hx2[i]=hx2[i-1]*p+(a[j].b[i]-'a'+1);
		}
		for(int i=1;i<=q;++i){
			for(int o=1;o<=b[i].l;o++){
				hx3[o]=hx3[o-1]*p+(b[i].a[o]-'a'+1);
				hx4[o]=hx4[o-1]*p+(b[i].b[o]-'a'+1);
			}
			for(int o=1,p=0;o<=b[i].l;o++){
				if(o>0&&b[i].a[o]!=a[j].a[p+1]){
					p=ne[p];
				}
				if(b[i].a[o]==a[j].a[p+1]){
					p++;
				}
				if(p==a[j].l){
					if(ch(i,j,o-a[j].l+1,o)){
						
						ans[i]++;
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
//it is time to freopon
