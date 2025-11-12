#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
string s[200010][3];
string t[200010][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	int fl=1;
	for(int i=1;i<=n;i++){
		int flag=-2;
		for(int j=0;j<s[i][1].size();i++){
			if(s[i][1][j]=='b' && flag){
				flag=-1;
				break;
			}
			if(s[i][1][j]=='b' && flag==0){
				flag=j;
			}
			if(s[i][1][j]!='b' && s[i][1][j]!='a'){
				flag=-1;
				break;
			}
		}
		if(flag<0){
			fl=0;
			break;
		}
	}
//	if(fl){
//		for(int i=1;i<=n;i++){
//			for(int k=1;k<=2;k++){
//				for(int j=0;j<s[i][1].size();i++){
//					if(s[i][1][j]=='b'){
//						
//					}
//				}
//			}
//		}
//		while(q--){
//			
//		}
//		
//		return 0;
//	}
	if(n<=1000){
		while(q--){
			string t1,t2;
			cin>>t1>>t2;
			t1=" "+t1;
			t2=" "+t2;
			if(t1.size()!=t2.size()){
				cout<<"0\n";
				continue;
			}
			int l=1,r=t1.size()-1;
			while(t1[l]==t2[l]){
				l++;
			}
			while(t1[r]==t2[r]){
				r--;
			}
			string dt1="",dt2="";
			for(int i=l;i<=r;i++){
				dt1+=t1[i];
				dt2+=t2[i];
			}
			int ans=0;
			for(int x=l;x>=1;x--){
				string ft1=dt1;
				string ft2=dt2;
				for(int y=r;y<t1.size();y++){
					if(y>r){
						ft1=ft1+t1[y];
						ft2=ft2+t2[y];
					}
					for(int i=1;i<=n;i++){
						if(s[i][1].size()==ft1.size()){
							if(ft1==s[i][1] && ft2==s[i][2]){
								ans++;
							}
						}
					}
//					cout<<ft1<<" "<<ft2<<"\n";
				}
				dt1=t1[x-1]+dt1;
				dt2=t2[x-1]+dt2;
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	return 0;
}
