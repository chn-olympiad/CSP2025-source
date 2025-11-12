#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a;
	int b;
	int c;
	string s; 
}k[10000];
struct st{
	int h;
	int bh;
}g[10000];
bool cmp(st q,st w){
	if(q.h>w.h){
		return true;
	}
	return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n,cnta=0,cntb=0,cntc=0,ans=0;
		for(int j=0;j<n;j++){
			k[j].s="";
		}
		cin >> n;
		for(int j=0;j<n;j++){
			cin >> k[j].a >> k[j].b >> k[j].c;
			int numa=k[j].a,numb=k[j].b,numc=k[j].c;
			if(numa>=numb&&numa>=numc){//排序一下选部门的顺序（a->b->c） 
				k[j].s+="a";
				if(numb>=numc){
					k[j].s+="bc";
				}else{
					k[j].s+="cb";
				}
			}else if(numb>numa&&numb>=numc){
				k[j].s+="b";
				if(numa>=numc){
					k[j].s+="ac";
				}else{
					k[j].s+="ca";
				}
			}else if(numc>numa&&numc>numb){
				k[j].s+="c";
				if(numa>=numb){
					k[j].s+="ab";
				}else{
					k[j].s+="ba";
				}
			}
			//cout << k[j].s << endl;
			if(k[j].s[0]=='a'){
				cnta++;
			}
			if(k[j].s[0]=='b'){
				cntb++;
			}
			if(k[j].s[0]=='c'){
				cntc++;
			}
		} 
		int maxn=n/2;
		//开始安排每个部门
		//cout << cnta << " " << cntb << " " << cntc << endl;
		for(int j=0;j<10000;j++){
			g[j].h=0;
			g[j].bh=0;
		}
		if(cnta<=maxn&&cntb<=maxn&&cntc<=maxn){
			for(int j=0;j<n;j++){
				if(k[j].s[0]=='a'){
					ans+=k[j].a;
				}
				if(k[j].s[0]=='b'){
					ans+=k[j].b;
				}
				if(k[j].s[0]=='c'){
					ans+=k[j].c;
				}
			}
		}else{
			//cout << 666 << endl;
			if(cnta>maxn){//a部门超了，找出最合适的(n/2)个人，其余超过的给第二选择
				int cntg=0;
				for(int j=0;j<n;j++){
					if(k[j].s[0]=='a'){
						g[cntg].h=k[j].a;
						g[cntg].bh=j;
						cntg++;
					}
				}
				sort(g,g+cntg,cmp);
				for(int j=0;j<maxn;j++){
					ans+=g[j].h;				
				}
				for(int j=maxn;j<cntg;j++){
					int zjl=g[j].bh;
					if(k[zjl].s[1]=='b'){
						ans+=k[zjl].b;
					}
					if(k[zjl].s[1]=='c'){
						ans+=k[zjl].c;
					}				
				}
			}
			else if(cntb>maxn){//b部门超了，找出最合适的(n/2)个人，其余超过的给第二选择
				int cntg=0; 
				for(int j=0;j<n;j++){//如果是b的人，记入结构体g的h，该下标记为g的bh 
					if(k[j].s[0]=='b'){
						g[cntg].h=k[j].b;
						g[cntg].bh=j;
						cntg++;
					}
				}
				sort(g,g+cntg,cmp);//排序结构体g 
				for(int j=0;j<maxn;j++){//在前maxn位的合格，计入ans 
					ans+=g[j].h;				
				}
				for(int j=maxn;j<cntg;j++){//在maxn-cntg之间的不合格，给第二选择 
					int zjl=g[j].bh;
					if(k[zjl].s[1]=='a'){//第二选择是a，计a 
						ans+=k[zjl].a;
					}
					if(k[zjl].s[1]=='c'){//第二选择是c，计c 
						ans+=k[zjl].c;
					}				
				}
			}
			else if(cntc>maxn){//c部门超了，找出最合适的(n/2)个人，其余超过的给第二选择
				int cntg=0;
				for(int j=0;j<n;j++){
					if(k[j].s[0]=='c'){
						g[cntg].h=k[j].c;
						g[cntg].bh=j;
						cntg++;
					}
				}
				sort(g,g+cntg,cmp);
				for(int j=0;j<maxn;j++){
					ans+=g[j].h;				
				}
				for(int j=maxn;j<cntg;j++){
					int zjl=g[j].bh;
					if(k[zjl].s[1]=='a'){
						ans+=k[zjl].a;
					}
					if(k[zjl].s[1]=='b'){
						ans+=k[zjl].b;
					}				
				}
			}
		}
		cout << ans << endl;
	} 
	return 0;
} 
