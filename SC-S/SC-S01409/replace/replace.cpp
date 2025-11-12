#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3];
string pre[200005],nxt[200005];
int pres[200005],nxts[200005];
int ls[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		string xs1="",xs2="";
		int l=s[i][1].size();
		int j=0,k=l-1;
		while(s[i][1][j]==s[i][2][j]) pre[i]+=s[i][2][j],j++;
		while(s[i][1][k]==s[i][2][k]) k--;
		for(int o=k+1;o<l;o++) nxt[i]+=s[i][1][o];
		pres[i]=pre[i].size(),nxts[i]=nxt[i].size();
		for(int l=j;l<=k;l++) xs1+=s[i][1][l],xs2+=s[i][2][l];
		s[i][1]=xs1,s[i][2]=xs2;
		ls[i]=s[i][1].size();
	}
	while(q--){
		string t1,t2;cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";continue;
		}
		string xt1="",xt2="";
		int j=0,k=t1.size()-1;
		while(t1[j]==t2[j]) j++;
		while(t1[k]==t2[k]) k--;
		for(int l=j;l<=k;l++) xt1+=t1[l],xt2+=t2[l];
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(ls[i]!=xt1.size()||ls[i]!=xt2.size()) continue;
//			cout<<xt1<<"\n"<<s[i][1]<<"\n"<<xt2<<s[i][2]<<"\n\n";
			if(xt1==s[i][1]&&xt2==s[i][2]){
				string ks1="",ks2="";
//				cout<<pres[i]<<" "<<nxts[i]<<"\n";
//				cout<<"k:"<<k<<" nxts:"<<nxts[i]<<"\n";
				for(int o=j-pres[i];o<=k+nxts[i];o++){
					if(o<0||o>t2.size())break;
					ks1+=t1[o],ks2+=t2[o];
				}
//				cout<<"ks1:"<<ks1<<"+ks2:"<<ks2<<"\n"<<(pre[i]+s[i][1]+nxt[i])<<"+"<<(pre[i]+s[i][2]+nxt[i])<<"\n";
				if(ks1==(pre[i]+s[i][1]+nxt[i]) && ks2==(pre[i]+s[i][2]+nxt[i]))cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
/*
2 1
a b
xa xb
xya xyb
*/
