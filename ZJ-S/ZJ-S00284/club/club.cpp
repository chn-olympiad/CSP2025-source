#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct node{
	int id,x,s;	
};
int t,n;
int a[N],b[N],c[N],al=0,bl=0,cl=0,aa[N],bb[N],cc[N],d3[N];
node d[N],d2[N];
bool cmp(node x,node y){
	if(x.x==y.x){
		if(d3[x.id]>d3[y.id])return 0;
		else return 1;
	}
	else return x.x>y.x;
}

void fz1(int x){
	int m;
	if(x==1){
		m=al;
		for(int i=1;i<=m;i++){
			d[i].x=bb[a[i]]-aa[a[i]];
			d2[i].x=cc[a[i]]-aa[a[i]];
		}
	}
	if(x==2){
		m=bl;
		for(int i=1;i<=m;i++){
			d[i].x=aa[b[i]]-bb[b[i]];
			d2[i].x=cc[b[i]]-bb[b[i]];
		}
	}
	if(x==3){
		m=cl;
		for(int i=1;i<=m;i++){
			d[i].x=aa[c[i]]-cc[c[i]];
			d2[i].x=bb[c[i]]-cc[c[i]];
		}
	}
	for(int i=1;i<=m;i++){
		if(d[i].x>=d2[i].x)d[i].s=1;
		else{
			d[i].s=2;
			d[i].x=d2[i].x;
		}
		if(x==1)d[i].id=a[i],d3[i]=aa[a[i]];
		if(x==2)d[i].id=b[i],d3[i]=bb[b[i]];
		if(x==3)d[i].id=c[i],d3[i]=cc[c[i]];
	}
	sort(d+1,d+m+1,cmp);
	if(x==1)
		for(int i=1;i<=m-n/2;i++){
			al--;
			if(d[i].s==1){
				bl++;
				b[bl]=d[i].id;
			}
			else{
				cl++;
				c[cl]=d[i].id;
			}
		}
	if(x==2)
		for(int i=1;i<=m-n/2;i++){
			bl--;
			if(d[i].s==1){
				al++;
				a[al]=d[i].id;
			}
			else{
				cl++;
				c[cl]=d[i].id;
			}
		}
	if(x==3)
		for(int i=1;i<=m-n/2;i++){
			cl--;
			if(d[i].s==1){
				al++;
				a[al]=d[i].id;
			}
			else{
				bl++;
				b[bl]=d[i].id;
			}
		}
}
void fz2(int x,int s){
	int m;
	if(x==1)m=al;
	if(x==2)m=bl;
	if(x==3)m=cl;
	if(s==1){
		if(x==2)
		for(int i=1;i<=m;i++){
			d[i].x=bb[b[i]]-cc[b[i]];
		}
		if(x==3)
		for(int i=1;i<=m;i++){
			d[i].x=cc[c[i]]-bb[c[i]];
		}
	}
	if(s==2){
		if(x==1)
		for(int i=1;i<=m;i++){
			d[i].x=aa[a[i]]-cc[a[i]];
		}
		if(x==3)
		for(int i=1;i<=m;i++){
			d[i].x=cc[c[i]]-aa[c[i]];
		}
	}
	if(s==3){
		if(x==2)
		for(int i=1;i<=m;i++){
			d[i].x=bb[b[i]]-aa[b[i]];
		}
		if(x==1)
		for(int i=1;i<=m;i++){
			d[i].x=aa[a[i]]-bb[a[i]];
		}
	}
	for(int i=1;i<=m;i++){
		if(x==1)d[i].id=a[i],d3[i]=aa[a[i]];
		if(x==2)d[i].id=b[i],d3[i]=bb[b[i]];
		if(x==3)d[i].id=c[i],d3[i]=cc[c[i]];
	}
	sort(d+1,d+m+1,cmp);
	if(x==1)
		for(int i=1;i<=m-n/2;i++){
			al--;
			if(s==2){
				bl++;
				b[bl]=d[i].id;
			}
			else{
				cl++;
				c[cl]=d[i].id;
			}
		}
	if(x==2)
		for(int i=1;i<=m-n/2;i++){
			bl--;
			if(s==1){
				al++;
				a[al]=d[i].id;
			}
			else{
				cl++;
				c[cl]=d[i].id;
			}
		}     
			
	if(x==3)
		for(int i=1;i<=m-n/2;i++){
			cl--;
			if(s==1){
				al++;
				a[al]=d[i].id;
			}
			else{
				bl++;
				b[bl]=d[i].id;
			}
		}     
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t){
		t--;
		cin>>n;
		al=0;bl=0;cl=0;
		for(int i=1;i<=n;i++){
			cin>>aa[i]>>bb[i]>>cc[i];
			if(max(aa[i],max(bb[i],cc[i]))==aa[i]){
				al++;
				a[al]=i;
			}
			else if(max(aa[i],max(bb[i],cc[i]))==bb[i]){
				bl++;
				b[bl]=i;
			}
			else{
				cl++;
				c[cl]=i;
			}
		}
		int t=0;
		if(al>n/2){
			fz1(1);
			t=1;
		}
		else if(bl>n/2){
			fz1(2);
			t=2;
		}
		else if(cl>n/2){
			fz1(3);
			t=3;
		}
		if(al>n/2)fz2(1,t);
		else if(bl>n/2)fz2(2,t);
		else if(cl>n/2)fz2(3,t);
		long long ans=0;
		for(int i=1;i<=al;i++){
			ans=ans+aa[a[i]];
		}
		for(int i=1;i<=bl;i++){
			ans=ans+bb[b[i]];
		}
		for(int i=1;i<=cl;i++){
			ans=ans+cc[c[i]];
		}
		cout<<ans<<endl;
	}
	return 0;
}
