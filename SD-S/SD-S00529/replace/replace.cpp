#include<bits/stdc++.h>

using namespace std;
const int N=2e5+5,L=5e6+5;
int read(){
	int sum=0,fg=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') fg=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*fg;
}

struct node{
	int len1,len2,val,id,res;
	node(){
		len1=len2=val=id=res=0;
	}
	bool operator<(const node &o) const{
		return len1<o.len1||(len1==o.len1&&len2<o.len2);
	}
} t[N];

bool cmp(const node &a,const node &b){
	return a.id<b.id;
}

int buc[L<<1],head[L];
vector<node> Q[L];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	for(int i=1;i<=n;++i){
		string s1,s2;
		cin>>s1>>s2;
		node s;
		int len1=s1.find('b');
		s.len2=s1.size()-len1;
		s.val=len1-s2.find('b');
		Q[len1].push_back(s);
	}
	for(int i=1;i<=q;++i){
		string t1,t2;
		cin>>t1>>t2;
		t[i].len1=t1.find('b');
		t[i].len2=t1.size()-t[i].len1;
		t[i].val=t[i].len1-t2.find('b');
		t[i].id=i;
	}
	for(int i=0;i<L;++i)
		if(!Q[i].empty()) sort(Q[i].begin(),Q[i].end());
	sort(t+1,t+q+1);
	for(int i=1;i<=q;++i){
		for(int j=0;j<=t[i].len1;++j)
			while(head[j]<Q[j].size()&&Q[j][head[j]].len2<=t[i].len2)
				buc[Q[j][head[j]++].val+L]++;
		t[i].res=buc[t[i].val+L];
	}
	sort(t+1,t+q+1,cmp);
	for(int i=1;i<=q;++i) printf("%d\n",t[i].res);
	return 0;
}


