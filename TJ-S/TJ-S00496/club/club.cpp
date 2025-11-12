#include<bits/stdc++.h>
using namespace std;
int n,t,aa,bb,cc,cnt,f,m;
struct node{
	int a,b,c;
}q[100005];
bool cma(node i,node j){
	return i.a>j.a;
}
bool cmb(node i,node j){
	return i.b>j.b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>q[i].a>>q[i].b>>q[i].c;
			aa=max(aa,q[i].a);
			bb=max(bb,q[i].b);
			cc=max(cc,q[i].c);
		}
		if(n==2){
			if(aa>=bb&&bb>=cc)cout<<aa+bb<<endl;
			else if(aa>=bb&&cc>=bb)cout<<aa+cc<<endl;
			else cout<<bb+cc<<endl;
		}
		else if(n==4){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					for(int k=1;k<=n;k++){
						for(int l=1;l<=n;l++){
							if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l){
								cnt=max(cnt,q[i].a+q[j].b+q[k].c+q[l].a);
								cnt=max(cnt,q[i].a+q[j].b+q[k].c+q[l].b);
								cnt=max(cnt,q[i].a+q[j].b+q[k].c+q[l].c);
								cnt=max(cnt,q[i].a+q[j].b+q[k].b+q[l].c);
								cnt=max(cnt,q[i].a+q[j].c+q[k].a+q[l].b);
								cnt=max(cnt,q[i].a+q[j].a+q[k].c+q[l].b);
								cnt=max(cnt,q[i].b+q[j].b+q[k].c+q[l].a);
								cnt=max(cnt,q[i].c+q[j].b+q[k].c+q[l].a);
								cnt=max(cnt,q[i].b+q[j].a+q[k].c+q[l].a);
								cnt=max(cnt,q[i].c+q[j].b+q[k].c+q[l].a);
								cnt=max(cnt,q[i].a+q[j].c+q[k].b+q[l].a);
								cnt=max(cnt,q[i].c+q[j].c+q[k].b+q[l].a);
								cnt=max(cnt,q[i].c+q[j].c+q[k].a+q[l].b);
								cnt=max(cnt,q[i].a+q[j].a+q[k].b+q[l].b);
								cnt=max(cnt,q[i].a+q[j].a+q[k].c+q[l].c);
								cnt=max(cnt,q[i].b+q[j].b+q[k].c+q[l].c);
								cnt=max(cnt,q[i].a+q[j].b+q[k].a+q[l].c);
								cnt=max(cnt,q[i].a+q[j].b+q[k].a+q[l].b);
								cnt=max(cnt,q[i].b+q[j].b+q[k].c+q[l].a);
								cnt=max(cnt,q[i].c+q[j].c+q[k].b+q[l].a);
								cnt=max(cnt,q[i].c+q[j].b+q[k].c+q[l].b);
								cnt=max(cnt,q[i].c+q[j].a+q[k].c+q[l].a);
								cnt=max(cnt,q[i].b+q[j].a+q[k].b+q[l].a);
								cnt=max(cnt,q[i].c+q[j].a+q[k].c+q[l].a);
								cnt=max(cnt,q[i].c+q[j].b+q[k].a+q[l].a);
								cnt=max(cnt,q[i].c+q[j].a+q[k].b+q[l].a);
								cnt=max(cnt,q[i].a+q[j].a+q[k].b+q[l].b);
								cnt=max(cnt,q[i].b+q[j].c+q[k].a+q[l].b);
								cnt=max(cnt,q[i].c+q[j].a+q[k].b+q[l].b);
								cnt=max(cnt,q[i].a+q[j].c+q[k].c+q[l].c);
								cnt=max(cnt,q[i].b+q[j].c+q[k].c+q[l].a);
								cnt=max(cnt,q[i].b+q[j].c+q[k].a+q[l].a);
								cnt=max(cnt,q[i].b+q[j].c+q[k].a+q[l].c);
								cnt=max(cnt,q[i].b+q[j].b+q[k].a+q[l].c);
								cnt=max(cnt,q[i].c+q[j].a+q[k].a+q[l].b);
								cnt=max(cnt,q[i].a+q[j].b+q[k].b+q[l].c);
								cnt=max(cnt,q[i].b+q[j].b+q[k].c+q[l].a);
								cout<<cnt<<endl;
								f=1;
								break;
							}
						}
						if(f)break;
					}
					if(f)break;
				}
				if(f)break;
			}
			if(f)break;
		}
		else if(bb==0&&cc==0){
			sort(q+1,q+n+1,cma);
			for(int i=1;i*2<=n;i++){
				cnt+=q[i].a;
			}
			cout<<cnt<<endl;
		}
		else if(cc==0){
			sort(q+1,q+n+1,cma);
			for(int i=1;i<=n;i++){
				if(q[i].a>q[i].b&&2*m<=n){
					cnt+=q[i].a;
					m++;	
				}
			}
			m=0;
			sort(q+1,q+n+1,cmb);
			for(int i=1;i<=n;i++){
				if(q[i].b>q[i].a&&2*m<=n){
					cnt+=q[i].b;
					m++;
				}
			}
			cout<<cnt<<endl;
		}
		else cout<<0<<endl;
		f=0;
		cnt=0;
		m=0;
		aa=0;
		bb=0;
		cc=0;
	}
	return 0;
}
