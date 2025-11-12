#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
const int P=998244353;
int n,m,c[N];
map<string,string> mp;
int pr[N],rp[N],kkl[N]; 
int ans=0;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >>n>>m;
	for(int i=0;i<n;i++){
		string s1,s2;
		cin >>s1>>s2;
		int isd=0;
		for(int j=0;j<s1.length();j++){
			if(s1[j]=='b'){
				isd=j;
				pr[i]=j;//Ç°×ºÊýÁ¿
				rp[i]=s1.length()-1-j; 
				break;
			}
		}for(int j=0;j<s1.length();j++){
			if(s2[j]=='b'){
				kkl[i]=j-isd;
			}
		}
		mp[s1]=s2;
	}
//	int ans=0;
	if(n<=100){
		while(m--){
			string t1,t2;
			cin >>t1>>t2;
			int lt1=t1.length();
			int lt2=t2.length();
			if(lt1!=lt2) cout <<0<<'\n';
			else{
				int cnt=0;
				for(int l=0;l<lt1;l++){
					for(int r=l;r<lt1;r++){
						bool flag=0;
						for(int k=0;k<l;k++){
							if(t1[k]!=t2[k]){
								flag=1;
								break;
							}
						}
						for(int k=r+1;k<lt1;k++){
							if(t1[k]!=t2[k]){
								flag=1;
								break;
							}
						}
						if(flag) continue;
						string yyt="";
						for(int k=l;k<=r;k++){
							yyt+=t1[k];
						}
						string yyp="";
						for(int k=l;k<=r;k++){
							yyp+=t2[k];
						}
						if(mp[yyt]==yyp) cnt++;
					}
				}
				cout <<cnt<<'\n';
			}
		}
	}
	
	else{
		while(m--){
			string t1,t2;
			cin >>t1>>t2;
			int lt1=t1.length();
			int lt2=t2.length();
			if(lt1!=lt2) cout <<0<<'\n';
			else{
				int idkk1=0,idkk2=0;
				int qj=0,hj=0;
				for(int i=0;i<lt1;i++){
					if(t1[i]=='b') {
					idkk1=i;
					qj=i;
					hj=lt1-i-1;
				}
					if(t2[i]=='b') idkk2=i;
				}
				int bgh=idkk2-idkk1;
				int cnt=0;
				for(int i=0;i<n;i++){
					if(pr[i]<=qj&&rp[i]<=hj&&kkl[i]==bgh){
						cnt++;
					}
				}
				cout <<cnt<<'\n';
			}
		}
	}
	return 0;
}
