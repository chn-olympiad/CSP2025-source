#include<bits/stdc++.h>
using namespace std;
int n,q;
int nxt[200020];
string str1[200020],str2[200020];
string ts,te;
int ans;
int maxn=0;
void kmp(string s,string t,string d){
	memset(nxt,0,sizeof(nxt));
	int lens=s.size();
	int lent=t.size();
	nxt[0]=-1;
	for(int i=1,j=0;i<lent;i++){
		while(j>=0&&t[i]!=t[j]) j=nxt[j];
		nxt[i]=j++;
		if(nxt[i]==-1) nxt[i]=0;
	}
	for(int i=0,j=0;i<lens;i++){
		while(j>=0&&s[i]!=t[j]) j=nxt[j];
		j++;
		if(j==lent){
		//	i-lent+1,i;
			string temp=s.substr(0,i-lent+1);
			temp+=d;
			temp+=s.substr(i+1,lens-i-1);
			if(temp==te) ans++;
			j--;
		}	
					
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str1[i]>>str2[i];
		int len=str2[i].size();
		maxn=max(maxn,len);
	} 	
	for(int i=1;i<=q;i++){
		cin>>ts>>te;
		ans=0;
		int l,r;
		for(int i=0;i<ts.size();i++){
			if(ts[i]!=te[i]){
				l=i;
				break;
			}
		}
		for(int i=ts.size()-1;i>=0;i--){
			if(ts[i]!=te[te.size()-ts.size()+i]){
				r=i;
				break;
			}
		}		
		if(maxn<r-l+1){
			cout<<0<<'\n';
			continue;
		}
		for(int j=1;j<=n;j++){
			kmp(ts,str1[j],str2[j]);
		} 
		cout<<ans<<'\n';
	}
	return 0;
}