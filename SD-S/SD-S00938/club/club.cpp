#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
int n;
struct S{
	int a1,a2,a3;
	int g,maxcnt;
	bool operator < (S b)const{
		return g<b.g;
	}
};
S clu(bool a,bool b,bool c,S tmp){
	int t1=-1e9,t2=-1e9,maxc=0;
	if(a&&t1<=tmp.a1){
		t2=t1;
		t1=tmp.a1;
		maxc=1;
	}
	else if(a&&t2<tmp.a1){
		t2=tmp.a1;
	}
	if(b&&t1<=tmp.a2){
		t2=t1;
		t1=tmp.a2;
		maxc=2;
	}
	else if(b&&t2<tmp.a2){
		t2=tmp.a2;
	}
	if(c&&t1<=tmp.a3){
		t2=t1;
		t1=tmp.a3;
		maxc=3;
	}
	else if(c&&t2<tmp.a3){
		t2=tmp.a3;
	}
	tmp.g=t1-t2;
	tmp.maxcnt=maxc;
	return tmp;
}
priority_queue<S> q;
int T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		while(q.size()) q.pop();
		cin>>n;
		for(int i=1;i<=n;i++){
			S tmp;
			scanf("%d%d%d",&tmp.a1,&tmp.a2,&tmp.a3);
			tmp=clu(1,1,1,tmp);
			q.push(tmp);
		}
		int jnum[]={0,0,0,0},jn[]={0,1,1,1},cnt=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			S tp=q.top();q.pop();
			while(jn[tp.maxcnt]==0){
				if(cnt==2){
					if(jn[1]){
						jnum[1]++;
						tp.maxcnt=1;
						tp.g=tp.a1;
					}
					else if(jn[2]){
						jnum[2]++;
						tp.maxcnt=2;
						tp.g=tp.a2;
					}
					else if(jn[3]){
						jnum[3]++;
						tp.maxcnt=3;
						tp.g=tp.a3;
					}
				}
				if(cnt==1){
					tp=clu(jn[1],jn[2],jn[3],tp);
				}
				q.push(tp);
				tp=q.top();q.pop();
			}
			if(tp.maxcnt==1){
				ans+=tp.a1;
				jnum[1]++;
				if(jnum[1]==n/2){
					cnt++;
					jn[1]=0;
				}
			}
			else if(tp.maxcnt==2){
				ans+=tp.a2;
				jnum[2]++;
				if(jnum[2]==n/2){
					cnt++;
					jn[2]=0;
				}
			}
			else if(tp.maxcnt==3){
				ans+=tp.a3;
				jnum[3]++;
				if(jnum[3]==n/2){
					cnt++;
					jn[3]=0;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
