#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,q,ans[N],scl[N],scr[N];
struct node{
	string a,b;
	int lth,be,en;
}use[N],qq[N];
struct node2{
	int id,bt;
}bt1[N],bt2[N];
bool find(int uid,int qid){
	string s4=use[uid].a,s3=qq[qid].a,s2=qq[qid].b,s1=use[uid].b;
	int l1=use[uid].lth,l2=qq[qid].lth;
	for (int i=0,to;i<=l2-l1;i=to){
		to=i+1;
		int st=0,jt=0;
		while (st<l1&&s1[st]==s2[st+i]){
			if (s2[to+jt-1]!=s1[jt]) to=st+i,jt=0;
			else jt++;
			st++;
		}
		if (!(st-l1)){
			bool f=1;
			for (int j=0;j<l1;++j) if (s3[i+j]!=s4[j]){f=0;break;}
			if (f) return 1;
		}
	}
	return 0;
}
inline bool cmp(node2 x,node2 y){return x.bt<y.bt;}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;++i){
		cin>>use[i].a>>use[i].b;
		use[i].lth=use[i].a.length();
		for (int j=0;j<use[i].lth;++j){
			if (use[i].a[j]!=use[i].b[j]) ++bt1[i].bt;
			bt1[i].id=i;
		}
	}
	sort(bt1+1,bt1+1+n,cmp);
	for (int i=1;i<=q;++i){
		cin>>qq[i].a>>qq[i].b;
		qq[i].lth=qq[i].a.length();
		for (int j=0;j<qq[i].lth;++j) if (qq[i].a[j]!=qq[i].b[j]) ++bt2[i].bt;
		bt2[i].id=i;
	}
	sort(bt2+1,bt2+q+1,cmp);
	for (int i=1,hou;i<=q;i=hou){
		int now=bt2[i].bt;
		hou=i+1;
		while (hou<=q&&(!(bt2[hou].bt-now))) ++hou;
		scl[now]=i,scr[now]=hou;
	}
	for (int i=1;i<=n;i++){
		int btt=bt1[i].bt,uid=bt1[i].id;
		for (int j=scl[btt];j<scr[btt];++j){
			int qid=bt2[j].id;
			if (use[uid].lth>qq[qid].lth) continue;
			if (find(uid,qid)) ++ans[qid];
		}
	}
	for (int i=1;i<=q;++i) cout<<ans[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
