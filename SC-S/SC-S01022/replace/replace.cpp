#include<bits/stdc++.h>
using namespace std;
int n,q;
string q1,q2,s1[1005],s2[1005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		int jsq=0;
		cin>>q1>>q2;
		for(int j=1;j<=n;j++){
			int len1=q1.size();
			int len=s1[j].size();
			for(int k=0;k<len1;k++){
				int xb=0,t=k;
				while(q1[k]==s1[j][xb]&&k<len1){
					k++,xb++;
				}
				if(xb!=0) k--;
				if(xb==len){
					string tmp=q1;
					int xb2=-1;
					for(int w=t;w<=t+len-1;w++) tmp[w]=s2[j][++xb2];
					if(tmp==q2) jsq++;
//					for(int w=0;w<tmp.size();w++) cout<<tmp[w];
//					cout<<'\n';
				}
			}
			
		}
		if(i!=q) cout<<jsq<<'\n';
		else cout<<jsq;
	}
	return 0;
}
//注意关注释