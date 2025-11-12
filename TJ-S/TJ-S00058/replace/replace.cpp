#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,cnt,cha_idd[N];
string s[N][2],t[N][2],str;
string sub(string s,int l,int r){return s.substr(l,r-l+1);}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin>>n>>q;
	if(n<=100){
		for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
		for(int i=1;i<=q;i++){
			cin>>t[i][0]>>t[i][1];
			cnt=0;
			for(int l=0;l<t[i][0].size();l++){
				for(int r=l;r<t[i][0].size();r++){
					for(int j=1;j<=n;j++){
						if(sub(t[i][0],l,r)==s[j][0]){
							if(sub(t[i][0],0,l-1)+s[j][1]+sub(t[i][0],r+1,t[i][0].size()-1)==t[i][1]){
								cnt++;
							}
						}
					}
				}
			}
			cout<<cnt<<"\n";
		}
	}else if(q!=1){
		for(int i=1;i<=n;i++){
			cin>>s[i][0]>>s[i][1];
			int id1,id2;
			for(int j=0;j<s[i][0].size();j++)if(s[i][0][j]=='b')id1=j;
			for(int j=0;j<s[i][1].size();j++)if(s[i][1][j]=='b')id2=j;
			cha_idd[i]=id1-id2;
		}
		for(int i=1;i<=q;i++){
			cin>>t[i][0]>>t[i][1];
			cnt=0;
			int cha_long=t[i][0].size()-t[i][1].size();
			int id1,id2,cha_id;
			for(int j=0;j<t[i][0].size();j++)if(t[i][0][j]=='b')id1=j;
			for(int j=0;j<t[i][1].size();j++)if(t[i][1][j]=='b')id2=j;
			cha_id=id1-id2;
			for(int j=1;j<=n;j++){
				if(s[i][0].size()-s[i][1].size()==cha_long&&cha_idd[j]==cha_id){
					cnt++;
				}
			}
			cout<<cnt<<"\n";
		}
	}else{
		for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
		for(int i=1;i<=q;i++){
			cin>>t[i][0]>>t[i][1];
			cnt=0;
			for(int l=0;l<t[i][0].size();l++){
				for(int r=l;r<t[i][0].size();r++){
					for(int j=1;j<=n;j++){
						if(sub(t[i][0],l,r)==s[j][0]){
							if(sub(t[i][0],0,l-1)+s[j][1]+sub(t[i][0],r+1,t[i][0].size()-1)==t[i][1]){
								cnt++;
							}
						}
					}
				}
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
} //ÆÚÍû10~35 
