#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e5+10;
int aa[N],bb[N],cc[N];
struct zhiyuan{
	int id,v;
};
struct person{
	zhiyuan z[4];
	int cur;
}p[N];
struct comp{
	int num,val;
}hehe[N];
bool cmp(comp x,comp y){
	return x.val<y.val;
}
signed main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int t;
	cin>>t;
	while(t--){
		int n,tmp=0,cnta=0,cntb=0,cntc=0;
		cin>>n;
		int m=n/2;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			int mx=max(a,max(b,c));
//			if(mx==a)
//			p[i]=(node){a,b,c};
//			
			tmp+=mx;
			if(mx==a){
				
				cnta++;
				aa[cnta]=i;
				p[i].z[1]=(zhiyuan){1,a};
				if(a-b<=a-c){
					p[i].z[2]=(zhiyuan){2,b};
					p[i].z[3]=(zhiyuan){3,c};
				}
				else{
					p[i].z[2]=(zhiyuan){3,c};
					p[i].z[3]=(zhiyuan){2,b};
				}
			}	
			else if(mx==b){
				cntb++;
				bb[cntb]=i;
				p[i].z[1]=(zhiyuan){2,b};
				if(b-a<=b-c){
					p[i].z[2]=(zhiyuan){1,a};
					p[i].z[3]=(zhiyuan){3,c};
				}
				else{
					p[i].z[2]=(zhiyuan){3,c};
					p[i].z[3]=(zhiyuan){1,a};
				}
			}
			else{
				cntc++;
				cc[cntc]=i;
				p[i].z[1]=(zhiyuan){3,c};
				if(c-b<=c-a){
					p[i].z[2]=(zhiyuan){2,b};
					p[i].z[3]=(zhiyuan){1,a};
				}
				else{
					p[i].z[2]=(zhiyuan){1,a};
					p[i].z[3]=(zhiyuan){2,b};
				}
			}
			p[i].cur=1;
		}
		if(cnta>m){
			int k=cnta-m;
			for(int i=1;i<=cnta;i++){
				hehe[i].val=p[aa[i]].z[p[aa[i]].cur].v-p[aa[i]].z[p[aa[i]].cur+1].v;
				hehe[i].num=aa[i];
			} 
			sort(hehe+1,hehe+1+cnta,cmp);
			for(int i=1;i<=k;i++){
				tmp-=hehe[i].val;
				p[hehe[i].num].cur++;
			}
			
		}
		if(cntb>m){
			int k=cntb-m;
			for(int i=1;i<=cntb;i++){
				hehe[i].val=p[bb[i]].z[p[bb[i]].cur].v-p[bb[i]].z[p[bb[i]].cur+1].v;
				hehe[i].num=bb[i];
			} 
			sort(hehe+1,hehe+1+cntb,cmp);
			for(int i=1;i<=k;i++){
				tmp-=hehe[i].val;
				p[hehe[i].num].cur++;
			}
			
		}
		if(cntc>m){
			int k=cntc-m;
			for(int i=1;i<=cntc;i++){
				hehe[i].val=p[cc[i]].z[p[cc[i]].cur].v-p[cc[i]].z[p[cc[i]].cur+1].v;
				hehe[i].num=cc[i];
			} 
			sort(hehe+1,hehe+1+cntc,cmp);
			for(int i=1;i<=k;i++){
				tmp-=hehe[i].val;
				p[hehe[i].num].cur++;
			}
			
		}
		cout<<tmp<<'\n';
	} 
	return 0;
}

