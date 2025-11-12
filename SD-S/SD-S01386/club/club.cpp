#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct GR{
	long long t;
	int id,cid;
};
struct cl{
	GR gr[5];
}mem[N];
bool cmp(GR x,GR y){
	return x.t>y.t;
}
bool cmp1(GR x,GR y){
	if (mem[x.cid].gr[1].t-mem[x.cid].gr[2].t!=mem[y.cid].gr[1].t-mem[y.cid].gr[2].t)
		return mem[x.cid].gr[1].t-mem[x.cid].gr[2].t>mem[y.cid].gr[1].t-mem[y.cid].gr[2].t;
	return x.t>y.t;
}
int T,n;
GR ti[5][N];
int len[5];
bool f[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for (int i=1;i<=T;i++){
		cin>>n;
		for (int j=1;j<=n;j++){
			cin>>mem[j].gr[1].t>>mem[j].gr[2].t>>mem[j].gr[3].t;
			mem[j].gr[1].id=1;
			mem[j].gr[2].id=2;
			mem[j].gr[3].id=3;
			mem[j].gr[1].cid=j;
			mem[j].gr[2].cid=j;
			mem[j].gr[3].cid=j;
			sort(mem[j].gr+1,mem[j].gr+4,cmp);
			ti[mem[j].gr[1].id][++len[mem[j].gr[1].id]]=mem[j].gr[1];
		}
		long long ans=0;
		for (int j=1;j<=3;j++){
			if (len[j]>=n/2){
				sort(ti[j]+1,ti[j]+1+len[j],cmp1);
				for (int k=n/2+1;k<=len[j];k++)
					ans+=mem[ti[j][k].cid].gr[2].t,f[ti[j][k].cid]=1;
			}
			len[j]=0;
		}
			
		for (int j=1;j<=n;j++){
			if (f[j]!=1)
				ans=ans+mem[j].gr[1].t;
			else
				f[j]=0;
		}
			
		cout<<ans<<endl;
	}
	return 0;
}
