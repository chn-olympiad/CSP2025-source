#include<bits/stdc++.h>



using namespace std ;
#define ull  unsigned long long
const int N=1e6+10;
vector<ull>s1[N],s2[N];
const ull bs=131;
ull qpow(ull x,ull y){
	ull ans=1;
	while(y){
		if(y&1)ans=ans*x;
		x=x*x;
		y>>=1;
	}
	return ans;
}
void makehs(string str,vector<ull>&hs){
	int n=str.size()-1;
	for(int i=1;i<=n;i++){
		hs[i]=hs[i-1]*bs+str[i];
	}
}
bool chkeq(vector<ull> &st,vector<ull> &ed,int l,int r){
	
	if(l>r)return 1;
	int len=r-l+1;
	ull ret=st[r]-st[l-1]*qpow(bs,len);
	return ed[len]==ret;
}
bool chkeqq(vector<ull> &st,vector<ull> &ed,int l,int r){
	if(l>r)return 1;
	int len=r-l+1;
	ull ret=st[r]-st[l-1]*qpow(bs,len);
	ull rett=ed[r]-ed[l-1]*qpow(bs,len);
	return rett==ret;
}
int lenn[N];
int main() {
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
		int n,q;
		cin>>n>>q;
	if(n>1e5){
		
	}
	else{
		for(int i=1;i<=n;i++){
			string ss,st;
			cin>>ss>>st;
			int len=st.size();
			ss=" "+ss;
			st=" "+st;
			s1[i].resize(len+10);
			s2[i].resize(len+10);
			lenn[i]=len;
			makehs(ss,s1[i]);
			makehs(st,s2[i]);
			}
		for(int i=1;i<=q;i++){
			string ts,tt;
			cin>>ts>>tt;
			if(ts.size()!=tt.size()){
				cout<<0<<endl;
				continue;
			}
			vector<ull>t1,t2;
			int len=tt.size();
			ts=" "+ts;
			tt=" "+tt;
			t1.resize(len+10);
			t2.resize(len+10);
			makehs(ts,t1);
			makehs(tt,t2);
			int tot=0;
			for(int j=1;j<=n;j++){
				int lenj=lenn[j];
				for(int k=1;k+lenj-1<=len;k++){
					int rr=k+lenj-1;
					
//					if(chkeq(t1,s1[j],k,rr))cout<<j<<" "<<k<<"$";
					if(chkeqq(t1,t2,1,k-1)&&chkeqq(t1,t2,rr+1,len)&&chkeq(t1,s1[j],k,rr)&&chkeq(t2,s2[j],k,rr))tot++;
				}
			}
			cout<<tot<<endl;
		}
	}
}
