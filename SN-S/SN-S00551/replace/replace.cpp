#include<bits/stdc++.h>
using namespace std;
map<string,string>mmp;
struct node{
	string a,b,c;
};
bool check(string a,string b,string c,string goal){
	queue<node>qe;
	node now;
	now.a=a,now.b=b,now.c=c;
	qe.push(now);
	    now=qe.front();
	    qe.pop();
	    string S=now.a+now.b+now.c;
	    if(S==goal && S.size()==goal.size())return true;
	    if(mmp.count(now.b)){
	    	node nxt;
	    	nxt.a=now.a,nxt.b=mmp[now.b],nxt.c=now.c;
	    	qe.push(nxt);
	}
	if(qe.empty())return false;
	now=qe.front();
	    qe.pop();
	    S=now.a+now.b+now.c;
	    if(S==goal && S.size()==goal.size())return true;
	return false;
}
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;cin>>a>>b;
		mmp[a]=b;
	}
	while(q--){
		int ans=0;
		string Now,End;cin>>Now>>End;
	    for(int alen=0;alen<Now.size()+1;alen++){
	    	for(int blen=0;blen<Now.size()+1;blen++){
	    		string A=Now.substr(0,alen);
	    		string B=Now.substr(alen,blen);
	    		string C;
	    		if(alen+blen>Now.size())continue;
	    		if(B.size()==0)continue;
	    		C=Now.substr(blen+alen);
	    	    if(check(A,B,C,End))ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
