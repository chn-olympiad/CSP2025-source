#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
striny str[N][2];
int leng[N],maxn;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str[i][1]>>str[i][2];
		leng[i]=str[i][1].length();
		maxn=max(maxn,leng[i]);
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int dif=0,lx=0,len=s1.length();
		bool f=1;
		for(int i=0;i<len;i++){
			if(s1[i]!=s2[i]&&f){
				dif++,f=0,lx=1;
				while(s1[i]!=s2[i])lx++,i++;
				f=1;
			}
		}
		if(dis>=2||lx>maxn){cout<<0<<endl;continue;}
		else cout<<1<<endl;
	}
	return 0;
}
