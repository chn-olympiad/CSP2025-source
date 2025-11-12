#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
constexpr unsigned long long MOD=100000000000000003ull;
int n,q,f2[6000010],f1n,dfn[6000010][2],cdfn,rt[200010][2],rtn,fln,fs[5000010],qx[200010],d[200010],fi,fzw;
string s1,s2;
unordered_map<unsigned long long,int> fpz;
struct{
	int sn[26];
	vector<int> snf,zw,qw;
}f1[6000010];
void cr1(int k,int dp){
	if(dp>fln){
		f1[k].zw.push_back(fzw);
		return;
	}
	if(!f1[k].sn[fs[dp]]){
		f1[k].sn[fs[dp]]=++f1n;
		f1[k].snf.push_back(f1n);
	}
	cr1(f1[k].sn[fs[dp]],dp+1);
}
int cr2(int k,int dp){
	if(dp>fln)
		return k;
	if(!f1[k].sn[fs[dp]]){
		f1[k].sn[fs[dp]]=++f1n;
		f1[k].snf.push_back(f1n);
	}
	return cr2(f1[k].sn[fs[dp]],dp+1);
}
void ycl(int k){
	dfn[k][0]=++cdfn;
	for(auto i:f1[k].snf)
		ycl(i);
	dfn[k][1]=cdfn;
}
int cw(int k,int dp){
	if(dp>fln || !f1[k].sn[fs[dp]])
		return dfn[k][0];
	return cw(f1[k].sn[fs[dp]],dp+1);
}
void bj(int k,int dp){
	if(dp>fln || !f1[k].sn[fs[dp]]){
		f1[k].qw.push_back(fi);
		return;
	}
	bj(f1[k].sn[fs[dp]],dp+1);
}
void gz(int k,int z){
	for(;k<=cdfn;k+=k&-k)
		f2[k]+=z;
}
int cz(int k){
	int d=0;
	for(;k;k-=k&-k)
		d+=f2[k];
	return d;
}
void qj(int k){
	for(auto i:f1[k].zw){
		gz(dfn[i][0],1);
		if(dfn[i][1]!=cdfn)
			gz(dfn[i][1]+1,-1);
	}
	for(auto i:f1[k].qw)
		d[i]=cz(qx[i]);
	for(auto i:f1[k].snf)
		qj(i);
	for(auto i:f1[k].zw){
		gz(dfn[i][0],-1);
		if(dfn[i][1]!=cdfn)
			gz(dfn[i][1]+1,1);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int fw1=0,fw2;
		for(int j=1;j<=s1.length();j++){
			if(s1[j-1]!=s2[j-1]){
				if(!fw1)
					fw1=j;
				fw2=j;
			}
		}
		if(!fw1)
			continue;
		unsigned long long fz=0;
		for(int j=fw1;j<=fw2;j++)
			fz=((fz*37+s1[j-1]-'a')%MOD*37+s2[j-1]-'a')%MOD;
		int irt;
		if(fpz.find(fz)==fpz.end()){
			fpz[fz]=++rtn;
			irt=rtn;
			rt[rtn][0]=++f1n;
			rt[rtn][1]=++f1n;
		}
		else
			irt=fpz[fz];
		fln=s1.length()-fw2;
		for(int j=fw2+1;j<=s1.length();j++)
			fs[j-fw2]=s1[j-1]-'a';
		fzw=cr2(rt[irt][1],1);
		fln=fw1-1;
		for(int j=fw1-1;j>=1;j--)
			fs[fw1-j]=s1[j-1]-'a';
		cr1(rt[irt][0],1);
	}
	for(int i=1;i<=rtn;i++)
		ycl(rt[i][1]);
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		if(s1.length()!=s2.length())
			continue;
		int fw1=0,fw2;
		for(int j=1;j<=s1.length();j++){
			if(s1[j-1]!=s2[j-1]){
				if(!fw1)
					fw1=j;
				fw2=j;
			}
		}
		unsigned long long fz=0;
		for(int j=fw1;j<=fw2;j++)
			fz=((fz*37+s1[j-1]-'a')%MOD*37+s2[j-1]-'a')%MOD;
		int irt;
		if(fpz.find(fz)==fpz.end())
			continue;
		else
			irt=fpz[fz];
		fln=s1.length()-fw2;
		for(int j=fw2+1;j<=s1.length();j++)
			fs[j-fw2]=s1[j-1]-'a';
		qx[i]=cw(rt[irt][1],1);
		fln=fw1-1;
		for(int j=fw1-1;j>=1;j--)
			fs[fw1-j]=s1[j-1]-'a';
		fi=i;
		bj(rt[irt][0],1);
	}
	for(int i=1;i<=rtn;i++)
		qj(rt[i][0]);
	for(int i=1;i<=q;i++)
		cout<<d[i]<<'\n';
	return 0;
}
