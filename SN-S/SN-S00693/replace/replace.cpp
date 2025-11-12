#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int P=13;
int n,q;
unsigned long long hash1[1005];
unsigned long long hash2[1005];
unsigned long long hash11[1005];
unsigned long long hash22[1005];
int l[1005];
unsigned long long bei[1005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n<=1000&&q<=1000){
		bei[0]=1;
		for(int i=1;i<=1000;i++)
			bei[i]=bei[i-1]*P;
		for(int i=1;i<=n;i++){
			string ss,sss;cin>>ss>>sss;
			int wei=ss.size();
			l[i]=wei;
			ss=' '+ss;
			sss=' '+sss;
			for(int j=1;j<=wei;j++)
				hash1[i]=hash1[i]*P+ss[j]-'a'+1;
			for(int j=1;j<=wei;j++)
				hash2[i]=hash2[i]*P+sss[j]-'a'+1;
		}
//		for(int i=1;i<=n;i++)
//			cout<<hash1[i]<<" "<<hash2[i]<<"\n";
		while(q--){
			string ss1,ss2;
			int wei;
			int ans=0;
			memset(hash11,0,sizeof(hash11));
			memset(hash22,0,sizeof(hash22));
			cin>>ss1>>ss2;
			wei=ss1.size();
			ss1=' '+ss1;
			for(int i=1;i<=wei;i++)
				hash11[i]=hash11[i-1]*P+ss1[i]-'a'+1;
			ss2=' '+ss2;
			for(int i=1;i<=wei;i++)
				hash22[i]=hash22[i-1]*P+ss2[i]-'a'+1;
//			cout<<hash11[wei]<<" "<<hash22[wei]<<"\n";
			for(int i=1;i<=n;i++){
				for(int j=1;j<=wei;j++){
					int r=j+l[i]-1;
//					cout<<i<<" "<<j<<" "<<r<<" ";
					if(r>wei)
						break;
					int ww=wei-r;
					unsigned long long cha1=hash1[i]*bei[ww];
					unsigned long long cha2=hash2[i]*bei[ww];
					unsigned long long pan1=hash11[r]-hash11[j-1];
//					cout<<pan1<<" "<<hash1[i]*bei[j-1]<<"\n";;
					if(pan1!=hash1[i]*bei[j-1])
						continue;
//					cout<<cha1<<" "<<cha2<<" ";
					unsigned long long pan=hash11[wei]-cha1+cha2;
//					cout<<pan<<'\n';
					if(pan==hash22[wei]){
						ans++;
						break;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex

*/
