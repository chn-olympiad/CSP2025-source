#include<bits/stdc++.h>
using namespace std;
int n,q,len,tl,tr,sr,cnt,flag,f,siz[200005];
string a,b,arr[200005][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>arr[i][1]>>arr[i][2];
		siz[i]=arr[i][1].size();
	}
	while(q--){
		cin>>a>>b;
		cnt=0;
		tl=0;
		tr=0;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		len=a.size();
		while(tl<len){
			for(int j=1;j<=n;j++){
				tr=tl;
				sr=0;
				flag=0;
				while(a[tr]==arr[j][1][sr] and b[tr]==arr[j][2][sr] and sr<siz[j]){
					tr++;
					sr++;
					if(sr==siz[j]-1 and a[tr]==arr[j][1][sr] and b[tr]==arr[j][2][sr]) flag=1;
				}
				if(flag==1){
					if(tr==len){
						cnt++;
						continue;
					}
					tr++;
					while(a[tr]==b[tr] and tr<=len) tr++;
					if(tr==len+1) cnt++;
				}
			}
			tl++;
			for(int i=0;i<tl;i++){
				if(a[i]!=b[i]){
					f=1;
					break;
				}
			}
			if(f==1){
				f=0;
				break;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
