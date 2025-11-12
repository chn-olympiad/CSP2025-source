#include <bits/stdc++.h>
using namespace std;
int n,k,q,l666=0;
string ss1[11111],ss2[11111];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>ss1[i]>>ss2[i];
	sort(ss1+1,ss1+n+1);
	sort(ss2+1,ss2+n+1);
	while(q--){
		string tt1,tt2,xx1="",yy1="",xx2="",yy2="";
		cin>>tt1>>tt2;
		int m=tt1.size(),ans=0,kk=m-1;
		for(kk=m-1;kk>=0&&yy1==yy2;kk--){
			yy1+=tt1[kk];
			yy2+=tt2[kk];
		}
		for(int i=0;i<m;i++){
			if(xx1!=xx2) break;
			string rr1="",rr2="";
			for(int j=i;j<m;j++){
				rr1+=tt1[j];
				rr2+=tt2[j];
				if(j<=kk) continue;
				for(int k=1;k<=n;k++){
					if(ss1[k]==rr1&&ss2[k]==rr2){
						ans++;
						break;
					}
				}
			}
			xx1+=tt1[i];
			xx2+=tt2[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
