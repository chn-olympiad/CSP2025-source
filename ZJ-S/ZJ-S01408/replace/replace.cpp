#include <bits/stdc++.h>
using namespace std;
#define M 1005
int n,q;
struct dui{
	string str1,str2;
};
dui sr[M];
int cnt[M][M];
int pi[M];
int ans;
string t1,t2;
void kmp(string a,string b,int x){
	memset(pi,0,sizeof(pi));
	string str3=b+"#"+a;
	int k=str3.size();
	int lb=b.size();
	for(int i=1;i<k;i++){
		int j=pi[i-1];
		while(j>0&&str3[j]!=str3[i])j=pi[j-1];
		if(str3[j]==str3[i])j++;
		pi[i]=j;
		if(j==lb){
			cnt[x][i-2*lb+1]=1;
			string ss=a;
			for(int y=i-2*lb+1;y<i-2*lb+1+lb;y++){
				ss[i]=sr[x].str2[i];
			}
			if(ss==t2)ans++;
		}
	}
}
int main(void){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>sr[i].str1>>sr[i].str2;
	for(int i=1;i<=q;i++){
		ans=0;
		memset(cnt,0,sizeof(cnt));
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			kmp(t1,sr[i].str1,i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
