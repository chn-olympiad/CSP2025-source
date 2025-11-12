#include<bits/stdc++.h>
using namespace std;
int n,q;
string t[200005][2];
int lens[5000005];//leni表示长度为i字符串第一个所处的位置 leni=0表示没有长度为i的字符串 
long long dp[5000005];
struct Team{
	string s1,s2;
};
Team s[200005];
bool cmp(Team a,Team b){
	
	if (a.s1.size()!=b.s1.size())  return a.s1.size()<b.s1.size();
	else return a.s1<b.s1;
}
long long ErFenSearch(long long left,long long right,string se){
	//左闭右闭区间 
	while (left<=right){
		long long mid=left+(right-left)/2;
		if (s[mid].s1<se){
			left=mid+1;
		}
		else if (s[mid].s1>se){
			right=mid-1;
		}
		else return mid;
	}
	return -1;
} 
void dfs(long long start,string sst,string sto){
	//开long long 
	long long len=sst.size(),answer=0;
	string NowS="",NowA="";
	if (start>len){
		dp[start]=1;
		return;
	}
	else if (dp[start]!=-1){
	    return;
	}
	
	for (long long i=start;i<=len;i++){
		NowS+=" ";
		NowA+=" ";
		long long lenN=NowS.size();
		NowS[lenN-1]=sst[i-1];
		NowA[lenN-1]=sto[i-1];
		if (NowS==NowA){
			dfs(i+start,sst,sto);
			answer+=dp[i+start];
			continue;
		}
		if (lens[lenN]<=0)  continue;
		long long left=lens[lenN],cnt=lenN+1;
		while (lens[cnt]==0){cnt++;}
		long long right=lens[cnt]-1;
		long long pl=ErFenSearch(left,right,NowS);
		if (pl==-1 || s[pl].s2!=NowA)  continue;
		//查找到了所需字符串
		dfs(i+start,sst,sto);
		answer+=dp[i+start];
	}
	dp[start]=answer;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s[i*2-1].s1>>s[i*2-1].s2;
		s[i*2].s1=s[i*2-1].s2;
		s[i*2].s2=s[i*2-1].s1;
	}
	sort(s+1,s+1+n*2,cmp);
	for (int i=1;i<=2*n;i++){
		if (s[i].s1.size()!=s[i-1].s1.size()){
			lens[s[i].s1.size()]=i;
		}
	}
	lens[s[2*n].s1.size()+1]=2*n+1;
	
	for (int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
	}
	for (int i=1;i<=q;i++){
		memset(dp,-1,sizeof(dp));
		dfs(1,t[i][0],t[i][1]);
		cout<<dp[1]<<"\n";
	}
	return 0;
}
