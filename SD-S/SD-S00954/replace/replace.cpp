#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map> 
#define ll long long
using namespace std;
int n,q;
const int base1=31,base2=131,Mod1=998244353,Mod2=1e9+7;
map<pair<ll,ll>,int> ma;
string s1[200005],s2[200005],t1[200005],t2[200005];
int LL[200005],RR[200005];
int su1=0,su2=0,fl1=0,cntb=0;
struct _{
	int x,y,op,val,id;
	bool operator<(const _ &B)const{
		if(x==B.x) return op<B.op;
		return x<B.x;
	}
};
map<ll,vector<_> > ma1;
int t[5000006];
int lowbit(int x){return x&-x;}
void add(int x,int y){
	x++;
	for(;x<=5000001;x+=lowbit(x)) t[x]+=y;
}
ll query(int x){
	ll res=0;
	x++;
	for(;x>0;x-=lowbit(x)) res+=t[x];
	return res;
}
ll an[200005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]!='a'&&s1[i][j]!='b') fl1=1;
			if(s2[i][j]!='a'&&s2[i][j]!='b') fl1=1;
		}
		su1+=s1[i].size()+s2[i].size();
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
		for(int j=0;j<t1[i].size();j++){
			if(t1[i][j]!='a'&&t1[i][j]!='b') fl1=1;
			if(t2[i][j]!='a'&&t2[i][j]!='b') fl1=1;
		}
		su2+=t1[i].size()+t2[i].size();
	}
//	if(su1<=2000&&su2<=2000){
//		for(int i=1;i<=n;i++){
//			ll sum1=0,sum2=0;
//			for(int j=0;j<s1[i].size();j++){
//				sum1=(sum1*base1%Mod1+(s1[i][j]-'a'+1))%Mod1;
//				sum2=(sum2*base2%Mod2+(s2[i][j]-'a'+1))%Mod2;
//			}
//			ma[{sum1,sum2}]++;
//		}
//		for(int i=1;i<=q;i++){
//			int L=0,R=t1[i].size();
//			for(int j=0;j<t1[i].size();j++){
//				if(t1[i][j]==t2[i][j]) L++;
//				else break;
//			}
//			for(int j=(int)t1[i].size()-1;j>=0;j--){
//				if(t1[i][j]==t2[i][j]) R--;
//				else break;
//			}
//			ll res=0;
//			for(int j=0;j<=L;j++){
//				ll sum1=0,sum2=0;
//				for(int k=j;k<t1[i].size();k++){
//					sum1=(sum1*base1%Mod1+t1[i][k]-'a'+1)%Mod1;
//					sum2=(sum2*base2%Mod2+t2[i][k]-'a'+1)%Mod2;
//					if(k>=R-1){
//						res+=ma[{sum1,sum2}];
//					}
//				}
//			}
//			cout<<res<<'\n';
//		}
//		return 0;
//	}
	if(fl1==0){
		for(int i=1;i<=n;i++){
			int it1,it2;
			for(int j=0;j<s1[i].size();j++){
				if(s1[i][j]=='b') it1=j;
				if(s2[i][j]=='b') it2=j;
			}
			ma1[it1-it2].push_back({it1,s1[i].size()-it1-1,1,0,0});
		}
		for(int i=1;i<=q;i++){
			int it1,it2;
			for(int j=0;j<t1[i].size();j++){
				if(t1[i][j]=='b') it1=j;
				if(t2[i][j]=='b') it2=j;
			}
			ma1[it1-it2].push_back({-1,t1[i].size()-it1-1,2,-1,i});
			ma1[it1-it2].push_back({it1,t1[i].size()-it1-1,2,1,i});
		}
		for(auto it=ma1.begin();it!=ma1.end();it++){
			vector<_> tmp=it->second;
			sort(tmp.begin(),tmp.end());
			for(int i=0;i<tmp.size();i++){
				_ r=tmp[i];
				if(r.op==1){
					add(r.y,1);
				}
				else{
					an[r.id]+=r.val*query(r.y);
				}
			}
		}
		for(int i=1;i<=q;i++) cout<<an[i]<<'\n';
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			if(s1[i]==s2[i]) continue;
			int l1=0,r1=s1[i].size();
			for(int j=0;j<s1[i].size();j++){
				if(s1[i][j]==s2[i][j]) l1++;
				else break;
			}
			LL[i]=l1;
		}
		for(int rr=1;rr<=q;rr++){
			int L=0,R=t1[rr].size()-1;
			for(int j=0;j<t1[rr].size();j++){
				if(t1[rr][j]==t2[rr][j]) L++;
				else break;
			}
			for(int j=(int)t1[rr].size()-1;j>=0;j--){
				if(t1[rr][j]==t2[rr][j]) R--;
				else break;
			}
			ll res=0;
			for(int i=1;i<=n;i++){
				int l1=LL[i];
//				if(s1[i]==s2[i]) continue;
//				int l1=0,r1=s1[i].size();
//				for(int j=0;j<s1[i].size();j++){
//					if(s1[i][j]==s2[i][j]) l1++;
//					else break;
//				}
//				for(int j=(int)s1[i].size()-1;j>=0;j--){
//					if(s1[i][j]==s2[i][j]) r1--;
//					else break;
//				}
//				r1--;
//				if(r1-l1!=R-L||l1>L||(int)s1[i].size()-r1>(int)t1[i].size()-R) continue;
				int be=L-l1;
//				cout<<be<<' ';
				if(be<0||be+s1[i].size()>t1[rr].size()||be+s1[i].size()-1<R) continue;
				int fl=0;
				for(int j=0;j<s1[i].size();j++){
					if(s1[i][j]!=t1[rr][be+j]||s2[i][j]!=t2[rr][be+j]){
						fl=1;
						break;
					}
				}
				if(!fl){
					res++;
//					cout<<'b'<<i<<' ';
				}
			}
			cout<<res<<'\n';
		}
		
	}
	return 0;
}
