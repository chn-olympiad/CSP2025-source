#include<cmath>
#include<vector>
#include<iostream>
using namespace std;

string s[200010][2],s2[5000010][2];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int www=1;www<=q;www++){
		string s21,s22;
		cin>>s21>>s22;
		int st=-1,ed=0;
		for(int i=0;i<s21.size();i++){
			if(s21[i]!=s22[i]){
				if(st==-1) st=i;
				ed=i;
			}
		}
		int ans=0;
		if(st==-1){
			for(int k=1;k<=n;k++){
				if(s[k][0].size()<ed-st+1) continue;
				for(int i=0;i<=(int)s21.size()-(int)s[k][0].size();i++){
					cout<<i<<' ';
					bool flag=1;
					for(int j=0;j<s[k][0].size();j++){
						if(s[k][0][j]!=s21[i+j]||s[k][1][j]!=s22[i+j]) {flag=0;break;}
					}
					if(flag) ans++;
				}
			}
			cout<<ans<<'\n';
		} else {
			for(int k=1;k<=n;k++){
				if(s[k][0].size()<ed-st+1) continue;
	//			cout<<max(0,ed-(int)s[i][0].size()+1)<<' '<<min(st,(int)s21.size()-(int)s[i][0].size())<<'\n';
				for(int i=max(0,ed-(int)s[k][0].size()+1);i<=min(st,(int)s21.size()-(int)s[k][0].size());i++){
//					cout<<i<<' ';
					bool flag=1;
					for(int j=0;j<s[k][0].size();j++){
						if(s[k][0][j]!=s21[i+j]||s[k][1][j]!=s22[i+j]) {flag=0;break;}
					}
					if(flag) ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

/*
//freopen
luogu 688674
bye, OI.
Once I thought I was still ok after whking for 4 months, but it's obviously I won't be over 200 pts.
May I participate NOIP ? But will it make any sense ?
You have been AFOed, but why holding such a dream ?
Getting nothing, but unwilling to give up...
18:26 bye.
*/
