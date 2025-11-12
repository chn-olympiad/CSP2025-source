#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;

int read(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*f;
} 

//int kmp[N];
//int get_kmp(const string &s,int x){
//	int len=s.size()-1;
//	int j=0;
//	for(int i=2;i<=len;i++){
//		while(j&&s[j+1]!=s[i])j=kmp[x][j];
//		if(s[j+1]==s[i])j++;
//		kmp[x][i]=j;
//	}
//}
//
//int solve(const string &s,const string &t){
//	int lens=size()-1,lent=t.size()-1;
//	int j=0;
//	for(int i=1;i<=lent;i++){
//		while(j&&s[i]!=)
//	}
//}

const int P=131;
const int mod=998244353;

int Pn[N];

void get_h(const string& s,vector<ll>& hash){
	int len=s.size()-1;
	for(int i=1;i<=len;i++){
		hash[i]=(hash[i-1]*P+s[i])%mod;
	}
}
int h(vector<ll>& hash,int l,int r){
	return 	(hash[r]-hash[l-1]+mod)%mod*Pn[l-1]; 
}
int ksm(int a,int b){
	int res=0;
	while(b){
		if(b&1)res=(ll)res*a%mod;
		a=(ll)a*a%mod;
		b>>=1;
	}
	return res;
}
void get_Pn(){
	Pn[0]=1;
	int tmp=ksm(P,mod-2);
	for(int i=1;i<N;i++)
		Pn[i]=(ll)Pn[i-1]*tmp%mod;
}

int n,q;
string s[N][3],t[N][3];
vector<ll> hs[N][3];
vector<ll> ht[N][3];

bool check(string& s){
	int len=s.size()-1;
	int tmp=0;
	for(int i=1;i<=len;i++)
		if(s[i]=='b')tmp++;
	return tmp==1;
}

struct node{
	int lc,l,r,id;
}qj[N],xw[N];
bool cmp(node x,node y){
	if(x.lc==y.lc)return x.r<y.r;
	return x.r<y.r;
}

vector<int> ls[N];
int lowbit(int x){return x&(-x);}
int tree[N];
void update(int x,int k){
	while(x<N){
		tree[x]++;
		x+=lowbit(x);
	}
}
int query(int x){
	int res=0;
	while(x){
		res+=tree[x];
		x-=lowbit(x);
	}
	return res;
}
int op[N],tot;
int maxlen=0;
int ans[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	n=read(),q=read();
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		s[i][1]=" "+s[i][1];
		s[i][2]=" "+s[i][2];
		int len=s[i][1].size();
		hs[i][1].resize(len);hs[i][2].resize(len);
		get_h(s[i][1],hs[i][1]);
		get_h(s[i][2],hs[i][2]);
		if(flag){
			flag&=check(s[i][1]);
			flag&=check(s[i][2]);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
		t[i][1]=" "+t[i][1];
		t[i][2]=" "+t[i][2];
		int len=t[i][1].size();
		ht[i][1].resize(len);ht[i][2].resize(len);
		get_h(t[i][1],ht[i][1]);
		get_h(t[i][2],ht[i][2]);
		if(flag){
			flag&=check(t[i][1]);
			flag&=check(t[i][2]);
		}
	}
	if(flag){
		for(int i=1;i<=n;i++){
			int x1,x2;
			int j=1;
			int len=s[i][j].size();
			maxlen=max(maxlen,len);
			for(int k=1;k<=len;k++)
				if(s[i][j][k]=='b'){
					x1=k;break;
				}
			j=2;
			for(int k=1;k<=len;k++)
				if(s[i][j][k]=='b'){
					x2=k;break;
				}
			qj[i].lc=x2-x1;
			qj[i].l=x1-1;
			qj[i].r=len-x1;
		}
		for(int i=1;i<=q;i++){
			int x1,x2;
			int j=1;
			int len=t[i][j].size();
			maxlen=max(maxlen,len);
			for(int k=1;k<=len;k++)
				if(t[i][j][k]=='b'){
					x1=k;break;
				}
			j=2;
			for(int k=1;k<=len;k++)
				if(t[i][j][k]=='b'){
					x2=k;break;
				}
			xw[i].lc=x2-x1;
			xw[i].l=x1-1;
			xw[i].r=len-x1;
			xw[i].id=i;
		}
		sort(qj+1,qj+1+n,cmp);
		sort(xw+1,xw+1+q,cmp);
		for(int i=1,j=0,k=1;k<=maxlen;k++){
			tot=0;i++;
			for(;i<=q&&xw[i].lc==xw[i+1].lc;i++){
				while(j+1<=n&&qj[j+1].lc==qj[i].lc&&qj[j+1].r<=xw[i].r){
					j++;
					update(qj[j].l,1);op[++tot]=qj[j].l;
				}
				ans[xw[i].id]=query(xw[i].r)-query(xw[i].l-1);
			}			
			for(int i=1;i<=tot;i++)
				update(op[i],-1);
		}
		for(int i=1;i<=q;i++)
			cout<<ans[i]<<"\n";
	}
	else{
		for(int i=1;i<=q;i++){
			int len=t[i][1].size()-1;
			int nans=0;
			for(int j=1;j<=n;j++){
				int lens=s[j][1].size()-1;
				for(int k=1;k+lens-1<=len;k++){
					int l=k,r=k+lens-1;
					if(h(ht[i][1],1,lens)==h(hs[j][1],l,r)&&h(ht[i][2],1,lens)==h(hs[j][2],l,r)&&
						h(ht[i][1],1,k-1)==h(ht[i][2],l,k-1)&&h(ht[i][1],r+1,len)==h(ht[i][2],r+1,len))
							nans++;
				}
			}
			cout<<nans<<"\n";
		}
	}
	
	return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
