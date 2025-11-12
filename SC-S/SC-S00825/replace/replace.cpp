#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define lint long long
#define line inline

line lint read(){
	lint x=0;int f=1;char c=getchar();
	while(c<'0' or c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' and c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

int n,Q,all_len,ans;
int net[20005][20005],sum[(lint)(5e6+5)];
string s1[20005],s2[20005],s3,s4;

line void get(string s,int k){
	int n=s.size();
	int t1=0,t2=-1;
	net[k][0]=-1;
	while(t1<n){
		if(t2==-1 or s[t1]==s[t2]) net[k][++t1]=++t2;
		else t2=net[k][t2];
	}
	return ;
}

line void kmp(string S1,string S2,int k){
	int len=S1.size(),LEN=S2.size();
	string s=s2[k];
	int t1=0,t2=0;
	while(t1<len){
		if(t2==-1 or S1[t1]==S2[t2]){
			t1+=1,t2+=1;
		}
		else t2=net[k][t2];
		if(t2==LEN){
			int st=t1-t2,ed=st+LEN;
//			cout<<"["<<st+1<<","<<ed<<"]\n";
//			cout<<"front:"<<sum[st]<<" back:"<<sum[all_len]-sum[ed]<<"\n";
			if(sum[st]==st and sum[all_len]-sum[ed]==all_len-ed){
				bool mark=true;
				for(int i=st;i<ed;++i){
					if(s[i-st]!=s4[i]){
						mark=false;
						break;
					}
				}
				if(mark) ans+=1;
			}
			t2=net[k][t2];
		}
	}
	return ;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	n=read(),Q=read();
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
		get(s1[i],i);
	}
	while(Q--){
		ans=0;
		cin>>s3>>s4;
		all_len=s3.size();
		for(int i=1;i<=all_len;++i){
			sum[i]=sum[i-1];
			if(s3[i-1]==s4[i-1]) sum[i]+=1;
		}
		for(int i=1;i<=n;++i){
			kmp(s3,s1[i],i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}