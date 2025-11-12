#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N=2e5+10,M=5e6+10,mod=1e9+7,mod1=998244353,P=131;
int n,q;
LL h[M],hh[M];

vector<LL> s1[N],s2[N];
vector<LL> s11[N],s22[N];

vector<LL> ss1,ss2;
vector<LL> ss11,ss22;
int L[N];

vector<LL> tmps,tmpss;

string a1[N],a2[N],p[2];
LL res=0;

void inith(){
	h[0]=1;
	hh[0]=1;
	for(int i=1;i<M;i++){
		h[i]=(h[i-1]*P)%mod;
		hh[i]=(hh[i-1]*P)%mod1;
	}
}

void init(string x){
	string b=x;
	int ll=b.length()-1;
	
	tmps.clear(),tmpss.clear();
	tmps.push_back(0);
	tmpss.push_back(0);
	for(int i=1;i<=ll;i++){
		LL c=(tmps[i-1]*P%mod+(b[i]-'a'+1))%mod;
		tmps.push_back(c);
		c=(tmpss[i-1]*P%mod1+(b[i]-'a'+1))%mod1;
		tmpss.push_back(c);
	}
}

LL get(vector<LL> dd,int l,int r,int op){
	if(op==1) return dd[r]-dd[l-1]*h[r-l+1];
	else return dd[r]-dd[l-1]*hh[r-l+1];
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	inith();
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>a2[i];
		L[i]=a1[i].length();
		a1[i]=' '+a1[i];
		a2[i]=' '+a2[i];

		init(a1[i]);
		s1[i]=tmps;
		s11[i]=tmpss;
		init(a2[i]);
		s2[i]=tmps;
		s22[i]=tmpss;
	}
	
	while(q--){
		cin>>p[0]>>p[1];
		int len=p[0].length();
		p[0]=' '+p[0];
		p[1]=' '+p[1];
		init(p[0]);
		ss1=tmps;
		ss11=tmpss;
		init(p[1]);
		ss2=tmps;
		ss22=tmpss;
		
		int l=-1,r=len-1;
		for(int i=1;i<=len;i++){
			if(p[0][i]!=p[1][i]){
				if(l==-1) l=i;
				r=i;
			}
		}
		
		res=0;
		for(int i=1;i<=n;i++){
			if(L[i]>len||L[i]<r-l+1) continue;
			for(int j=1;j+(r-l+1)-1<=L[i];j++){
				if(get(s1[i],j,j+(r-l+1)-1,1)==get(ss1,l,r,1)&&get(s11[i],j,j+(r-l+1)-1,2)==get(ss11,l,r,2)){
					if(get(s2[i],j,j+(r-l+1)-1,1)==get(ss2,l,r,1)&&get(s22[i],j,j+(r-l+1)-1,2)==get(ss22,l,r,2)){
						res++;
					}
				}
			}
		}
		
		printf("%lld\n",res);
	}
	return 0;
}
