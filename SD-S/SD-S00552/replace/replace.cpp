#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int kmp[1005][2005],ans=0;
string r[1005],B[1005];

void init(string b,int lb,int k){
	int j=0;
	for(int i=2;i<=lb;i++){
		while(j and b[i]!=b[j+1]) j=kmp[k][j];
		if(b[i]==b[j+1]) j++;
		kmp[k][i]=j;
	}
}
void KMP(string a,string b,int la,int lb,int k,string fi){
	int j=0;
	for(int i=1;i<=la;i++){
		
		while(j and a[i]!=b[j+1]) {
			j=kmp[k][j];
		}
		if(a[i]==b[j+1]) {
			j++;
		}
		if(j==lb){
			string t=a.substr(1,i-lb)+r[k]+a.substr(i+1,la-i);
			
			if(t==fi) ans++;
			j=kmp[k][j];
		}
	}
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>B[i];
		B[i]=" "+B[i];
		init(B[i],B[i].size()-1,i);
		cin>>r[i];
	}
	while(q--){
		string a,fi;
		cin>>a>>fi;
		a=" "+a;
		for(int i=1;i<=n;i++){
			//cout<<i<<' ';
			KMP(a,B[i],a.size()-1,B[i].size()-1,i,fi);
		}
		cout<<ans<<"\n";
		ans=0;
	}
	
}

