#include<bits/stdc++.h>
using namespace std;
const int NN=2e5+5;
int n,q,lens[NN],lent[NN];
string s[NN][2],t[NN][2];
int FindB(const string&x,int len){
	for(int j=0;j<len;j++){
		if(x[j]=='b')return j;
	}
}
struct Word{
	int le,ri,dif,typ;
	bool operator<(const Word&x)const{
		if(dif==x.dif){
			if(le==x.le){
				return typ<x.typ;
			}
			return le<x.le;
		}
		return dif<x.dif;
	}
}w[2*NN];
int tot,val[2*NN],tot_val;
Word Trans(const string&x,const string&y,int len,int typ){
	int pos0=FindB(x,len),pos1=FindB(y,len); 
	val[++tot_val]=len-pos1-1;
	return Word{pos0+1,len-pos1-1,pos0-pos1,typ};
}
#define ll long long
int ans[NN],tri[2*NN];
int Find(int x){
	return lower_bound(val+1,val+tot_val+1,x)-val;
}
void Upd(int x,int Val){
	for(int i=x;i<=tot_val;i+=(i&(-i)))tri[i]+=Val;
}
int Sum(int x){
	int ret=0;
	for(int i=x;i>0;i-=(i&(-i)))ret+=tri[i];
	return ret;
}
const ll Mod[2]={1e9+21,1e9+9};
const int LL=2005,NMIN=1e3+5;
const ll bs=119;
ll Hs[NMIN][2][2];
ll Ecd(const string&x,int len,int typ){
	ll ret=0;
	for(int i=0;i<len;i++){
		ret=(ret*bs)%Mod[typ];
		ret=(ret+x[i])%Mod[typ];
	}
	return ret;
}
ll Hl[2][2][LL];//0/1,mod 
void Ecd2(const string&x,int len,int typ1,int typ2){
	Hl[typ1][typ2][0]=0;
	for(int i=1;i<=len;i++){
		Hl[typ1][typ2][i]=(Hl[typ1][typ2][i-1]*bs%Mod[typ2]+x[i-1])%Mod[typ2];
	}
}
ll px[2][LL];
ll Get(int L,int R,int typ1,int typ2){
	ll Val=(Hl[typ1][typ2][R]-Hl[typ1][typ2][L-1]*px[typ2][R-L+1]%Mod[typ2]+Mod[typ2])%Mod[typ2];
	return Val;
}
bool Check(int L,int R,int num,int typ1){
	return (Get(L,R,typ1,0)==Hs[num][typ1][0])&&(Get(L,R,typ1,1)==Hs[num][typ1][1]);
}
bool Change(int L,int R,int len,ll*Val){
	int dist=len-R;
	ll Val0=(Hl[0][0][len]-Get(L,R,0,0)*px[0][dist]%Mod[0]+Mod[0])%Mod[0];
	Val0=(Val0+Val[0]*px[0][dist]%Mod[0])%Mod[0];
	ll Val1=(Hl[0][1][len]-Get(L,R,0,1)*px[1][dist]%Mod[1]+Mod[1])%Mod[1];
	Val1=(Val1+Val[1]*px[1][dist]%Mod[1])%Mod[1];
	return (Val0==Hl[1][0][len])&&(Val1==Hl[1][1][len]);
}
int cntB(string x,int len){
	int ret=0;
	for(int i=0;i<len;i++)ret+=(x[i]=='b');
	return ret;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for(int i=0;i<2;i++){
		px[i][0]=1;
		for(int j=1;j<LL;j++)px[i][j]=px[i][j-1]*bs%Mod[i];
	}
	cin>>n>>q;
	tot=0;
	bool flagB=1;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		lens[i]=s[i][0].size();
		w[++tot]=Trans(s[i][0],s[i][1],lens[i],0);
		flagB=flagB&&(cntB(s[i][0],lens[i])==1);
		flagB=flagB&&(cntB(s[i][0],lens[i])==1);
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		lent[i]=t[i][0].size();
		w[++tot]=Trans(t[i][0],t[i][1],lent[i],i);
		flagB=flagB&&(cntB(t[i][0],lent[i])==1);
		flagB=flagB&&(cntB(t[i][0],lent[i])==1);
	}
//	cout<<tot<<'\n';
	if(flagB){
		sort(w+1,w+tot+1);
		sort(val+1,val+tot_val+1);
		tot_val=unique(val+1,val+tot_val+1)-val-1; 
		for(int i=1;i<=tot;i++)w[i].ri=Find(w[i].ri);
		for(int i=1;i<=tot;i++){
//			cout<<i<<'\n';
			int ii=i;//[i,ii]
			while(ii+1<=tot&&w[ii+1].dif==w[i].dif)ii++;
//			cout<<"Sec 1"<<'\n';
			for(int j=i;j<=ii;j++){
				Word W=w[j];
				if(W.typ==0){
					Upd(W.ri,1);
				}else{
//					cout<<"Sum "; 
					ans[W.typ]=Sum(W.ri);
				}
			}
//			cout<<"Sec 2"<<'\n';
			for(int j=i;j<=ii;j++){
				Word W=w[j];
				if(W.typ==0){
					Upd(W.ri,-1);
				}
			}
			i=ii;
		}
		for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	}else{
		for(int i=1;i<=n;i++){
			Hs[i][0][0]=Ecd(s[i][0],lens[i],0);
			Hs[i][0][1]=Ecd(s[i][0],lens[i],1);
			Hs[i][1][0]=Ecd(s[i][1],lens[i],0);
			Hs[i][1][1]=Ecd(s[i][1],lens[i],1);
		}
		for(int i=1;i<=q;i++){
			int ret=0;
			Ecd2(t[i][0],lent[i],0,0);
			Ecd2(t[i][0],lent[i],0,1);
			Ecd2(t[i][1],lent[i],1,0);
			Ecd2(t[i][1],lent[i],1,1);
			for(int j=1;j<=n;j++){
				if(lens[j]>lent[i])continue;
				for(int k=0;k+lens[j]-1<lent[i];k++){
					if(Check(k+1,k+lens[j],j,0)&&Change(k+1,k+lens[j],lent[i],Hs[j][1])){
						ret++;
					}
				}
			}
			cout<<ret<<'\n';
		}
	}
	return 0;
}
