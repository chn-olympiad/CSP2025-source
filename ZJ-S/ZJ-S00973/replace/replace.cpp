#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[n+10],b[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		string sa,sb;
		cin>>sa>>sb;
		int l=-1,r=-1,leng=sa.length();
		for(int i=0;i<leng;i++){
			if(sa[i]!=sb[i]){
				if(l==-1){
					l=i;
				}
				r=i;
			}
		}
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=l;j++){
				if(sb[j]==b[i][0]){
					int k=0;
					for(;k<b[i].length()&&k<leng;k++){
						if(sb[j+k]!=b[i][k]){
							k=-1;
							break;
						}
					}
					if(k>=r){
						res++;
					}
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
