#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,ans;
struct node{
	int a,b,c;
}s[N];

void solve(){
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
	}
	priority_queue<int> qa,qb,qc;
	for(int i=1;i<=n;i++){
		if(s[i].a>=s[i].b&&s[i].a>=s[i].c){
			qa.push(max(s[i].b,s[i].c)-s[i].a);
			ans+=s[i].a;
			if(qa.size()>n/2){
				int tmp=qa.top();
				ans+=tmp;
				qa.pop();
			}
		}else if(s[i].b>=s[i].a&&s[i].b>=s[i].c){
			qb.push(max(s[i].a,s[i].c)-s[i].b);
			ans+=s[i].b;
			if(qb.size()>n/2){
				int tmp=qb.top();
				ans+=tmp;
				qb.pop();
			}
		}else{
			qc.push(max(s[i].a,s[i].b)-s[i].c);
			ans+=s[i].c;
			if(qc.size()>n/2){
				int tmp=qc.top();
				ans+=tmp;
				qc.pop();
			}
		}
	}
	printf("%d\n",ans);
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
