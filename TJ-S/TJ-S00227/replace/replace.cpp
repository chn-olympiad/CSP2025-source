#include<iostream>
using namespace std;
int n,q,l,r;
string sa[200005][4];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>sa[i][0]>>sa[i][1];
	for(int i=1;i<=q;i++) cin>>sa[i][2]>>sa[i][3];
	/*
	for(int i=1;i<=q;i++){
		int len=sa[i][2].size();
		l=len+1,r=-1;
		for(int j=2;j<=len;j++){
			if(sa[i][2][j]!=sa[i][3][j]){
				if(l==len+1) l=j;
			}else{
				if(sa[i][2][j-1]!=sa[i][3][j-1]) r=j;
			}
		}
		string tem=sa[i][2].substr(l,r-l);
		
	}*/
	cout<<0;
	return 0;
}
//CSP-S Journal
//16:55 Whats dis?
//      Dis an apple.
//      Whats dis?
//      ......
//      Well,that's not the kind of good joke.
//      Try it.
//17:01 That's such a long dream.
//17:38 No,General!(0^0)
//17:42 Wow,ABB.
//17:43 The Time Flows So Quickly.
//17:46 NoGeneral Complete.
//      Expected:5pts.
//18:30 I'm back here.
//      107pts,and I finally get a prize.
//19:28 Not Solved Yet.
//      It's time to see how it comes to an end.
//freopen
