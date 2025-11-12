#include<bits/stdc++.h>
using namespace std;
string Qz[200100],Qy[200100],Az[200100],Ay[200100];
int n,q,ans[200100];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int k=1;k<=q;k++){
		string wa,wb,he,be;
		cin>>wa>>wb;
		bool t=0;
		for(int i=0;i<wa.size();i++){
			if(wa[i]!=wb[i]){
				t=1;
				Qz[k]+=wa[i];Qz[k]+=he;he="";
				Qy[k]+=wb[i];Qy[k]+=be;be="";
			}
			else if(t){
				he+=wa[i];be+=wb[i];
			}
		}
	}
	for(int k=1;k<=n;k++){
		string wa,wb,he,be;
		cin>>wa>>wb;
		bool t=0;
		for(int i=0;i<max(wa.size(),wb.size());i++){
			if(wa[i]!=wb[i]){
				t=1;
				Az[k]+=wa[i];Az[k]+=he;he="";
				Ay[k]+=wb[i];Ay[k]+=be;be="";
			}
			else if(t) he+=wa[i],be+=wb[i];
		}
		for(int i=1;i<=q;i++){t=1;
			if(Qz[i].size()==Az[k].size()&&Qy[i].size()==Ay[k].size()){
				for(int j=0;j<max(Qz[i].size(),Qy[i].size());j++){
					if(Qz[i][j]!=Az[k][j]||Qy[i][j]!=Ay[k][j]) t=0,j=Qz[i].size();
				}
				if(t) ans[i]++;
			}
		}
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
