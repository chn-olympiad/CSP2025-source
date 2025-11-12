#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
vector<LL>Next[N];
LL n,q;
string s1[N],s2[N],t1,t2;
void Get_Next(string st,LL Num){
	LL j=0,k=-1,len=st.size();
	for(int i=0;i<len;i++) Next[Num].push_back(0);
	Next[Num][0]=-1;
	while(j<len){
		if(k==-1||st[j]==st[k]) Next[Num][++j]=++k;
		else k=Next[Num][k];
	}
}
LL KMP(string s1,string s2,string r,string a,LL Num){
	LL i=0,j=0,ln1=s1.size(),ln2=s2.size(),ans=0;
	while(i<ln1&&j<ln2){
		if(j==-1||s1[i]==s2[j]) i++,j++;
		else j=Next[Num][j];
		if(j>=ln2){
			string st=s1;LL tmp=i-ln2;
			for(int k=0;k<r.size();k++){
				st[tmp]=r[k];tmp++;
			}
		//	cout<<st<<" "<<a<<"\n";
			if(st==a) ans++;
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		Get_Next(s1[i],i);
	} 
	while(q--){
		cin>>t1>>t2;
		LL ans=0;
		for(int i=1;i<=n;i++){
			ans+=KMP(t1,s1[i],s2[i],t2,i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
