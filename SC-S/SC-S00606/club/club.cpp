#include<bits/stdc++.h>
using namespace std;
struct qw{
	long long a;
	long long b;
	long long c;
	int op;
	bool l=0;
};
struct qq{
	long long a;
	long long id;
};
bool cmp(qq a,qq b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		bool lll=1,lo=1;
		vector<qw> aa(n+1);
		vector<qq> q(n+1),w(n+1),e(n+1);
		for(int i=0;i<n;i++){
			cin>>aa[i].a>>aa[i].b>>aa[i].c;
			if(aa[i].c!=0){
				lll=0;
				lo=0;
			}
			else if(aa[i].b!=0)lo=0;
			if(aa[i].a>aa[i].b&&aa[i].a>aa[i].c)aa[i].op=1;
			else if(aa[i].b>aa[i].c&&aa[i].b>aa[i].a)aa[i].op=2;
			else {
				aa[i].op=3;
			}
			q[i].a=aa[i].a;
			w[i].a=aa[i].b;
			e[i].a=aa[i].c;
			q[i].id=i;
			w[i].id=i;
			e[i].id=i;
		}
		sort(q.begin(),q.end(),cmp);
		int nnm=n%2;
		if(lo){
			long long ans=0;
			for(int i=0;i<n/2+nnm;i++){
				ans+=q[i].a;
			}
			cout<<ans<<'\n';
			continue;
		}
		sort(w.begin(),w.end(),cmp);
		if(lll){
			long long ans=0;
			long long sum=0,lop=0;
			for(int i=0;i<n;i++){
				if(aa[q[i].id].op==1&&aa[q[i].id].l==0&&sum<n/2+nnm){
					ans+=aa[q[i].id].a;
					aa[q[i].id].l=1;
					sum++;
				}
				else if(aa[w[i].id].l==0&&lop<n/2+nnm){
					ans+=aa[w[i].id].b;
					aa[w[i].id].l=1;
					lop++;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		sort(e.begin(),e.end(),cmp);
		long long r=0,tt=0,y=0;
		long long nn=n/2;
		
		long long ans=0;
		long long nm=n;
		for(int i=0;i<n;i++){
			if(aa[q[i].id].op==1&&aa[q[i].id].l==0){
				if(r<nn+nnm){
					r++;
					ans+=aa[q[i].id].a;
					aa[q[i].id].l=1;
					nm--;
					
				}
			}
			else if(aa[w[i].id].op==2&&aa[w[i].id].l==0){
				if(tt<nn+nnm){
					tt++;
					ans+=aa[w[i].id].a;
					aa[w[i].id].l=1;
					nm--;
				}
			}
			else if(aa[e[i].id].op==3&&aa[e[i].id].l==0){
				if(y<nn+nnm){
					y++;
					ans+=aa[e[i].id].a;
					aa[e[i].id].l=1;
					nm--;
				}
			}
		}
		if(nm!=0){
			vector<qw> aaa;
			vector<qq> qqq,www,eee;
			for(int i=0;i<n;i++){
				
				if(!aa[i].l){
					
					if(aa[i].op==1){
						if(r<n/2+nnm){
							ans+=aa[i].a;
							r++;
							aa[i].l=1;
						}
					}
					else if(aa[i].op==2){
						if(tt<n/2+nnm){
							ans+=aa[i].b;
							tt++;
							aa[i].l=1;
						}
					}
					else if(aa[i].op==3){
						if(y<n/2+nnm){
							ans+=aa[i].c;
							y++;
							aa[i].l=1;
						}
					}
					
				}
			}
			
		}
		cout<<ans<<'\n';
	}
	return 0;
} 