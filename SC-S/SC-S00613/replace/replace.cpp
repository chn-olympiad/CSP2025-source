#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
const int N=2e5+5,B=233,L=5e6+10;
int n,q;
ull pre[N],mid[N],aft[N];int p1[N],p2[N],len[N];
ull has[L],bas[L];
ull sub(int l,int r){
	if(l>r)return 0;
	return has[r]-has[l-1]*bas[r-l+1];
}
unordered_map<ull,vector<int>>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	bas[0]=1;rep(i,1,5000000)bas[i]=bas[i-1]*B;
	cin>>n>>q;
	rep(i,1,n){
		string s1,s2;cin>>s1>>s2;len[i]=s1.size();
		if(s1==s2){
			continue;
		}
		rep(j,0,(int)s1.size()-1){
			if(s1[j]!=s2[j]){p1[i]=j;break;}
			pre[i]=pre[i]*B+s1[j];
		}
		per(j,(int)s1.size()-1,0){
			if(s1[j]!=s2[j]){p2[i]=j;break;}
		}
		rep(j,p2[i]+1,(int)s1.size()-1)aft[i]=aft[i]*B+s1[j];
		rep(j,p1[i],p2[i])mid[i]=mid[i]*B+s1[j];
		rep(j,p1[i],p2[i])mid[i]=mid[i]*B+s2[j];
		mp[mid[i]].push_back(i);
	}
	rep(i,1,q){
		string t1,t2;cin>>t1>>t2;
		if(t1.size()!=t2.size())printf("0\n");
		else{
			int pp1=0,pp2=0;
			rep(j,1,(int)t1.size())has[j]=has[j-1]*B+t1[j-1];
			rep(j,0,(int)t1.size()-1){
				if(t1[j]!=t2[j]){pp1=j;break;}
			}
			per(j,(int)t1.size()-1,0){
				if(t1[j]!=t2[j]){pp2=j;break;}
			}
			ull tt=0;
			rep(j,pp1,pp2)tt=tt*B+t1[j];
			rep(j,pp1,pp2)tt=tt*B+t2[j];
			int cnt=0;
			for(int j:mp[tt]){
				if(pp1-(p1[j])+1>=1&&pp2+2+(len[j]-p2[j]-1)-1<=t1.size()&&pre[j]==sub(pp1-(p1[j])+1,pp1)&&aft[j]==sub(pp2+2,pp2+2+(len[j]-p2[j]-1)-1))cnt++;
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}