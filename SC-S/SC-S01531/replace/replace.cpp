#include<bits/stdc++.h>
using namespace std;
int n,q,an[1000005][30],bn[1000005][30];
string a[200005],b[200005],q1,q2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int ooooo=1;ooooo<=q;ooooo++){
		cin>>q1>>q2;
		int l,r,len=q1.size(),res=0;
		for(l=0;l<len;l++) if(q1[l]!=q2[l]) break; 
		for(r=len-1;r>=0;r--) if(q1[r]!=q2[r]) break;
		for(int i=1;i<=n;i++){
			string A=a[i],B=b[i];
			if((int)A.size()>len) continue;
			if((int)A.size()==len){
				if((B==q2)&&(A==q1)) res++;
				continue;
			}
			for(int o=0;o<=len-(int)A.size();o++){
				if(o>l) break;
				if(A[0]==q1[o]&&B[0]==q2[o]){
					int L=0,R=o;
					while(A[L]==q1[R]&&B[L]==q2[R]&&L<(int)A.size()-1) L++,R++;
					if(R>=r) res++;
				}
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}
/*
每次都想装作很倔强（
好恶心的T3
暴力水20分吧
只有280 看看能不能进wc/kk/kk
*/
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/