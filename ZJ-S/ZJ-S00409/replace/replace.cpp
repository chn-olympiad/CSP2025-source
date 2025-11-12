#include<bits/stdc++.h>
using namespace std;
int n,q,st,ed;
string a[200005],b[200005],sa,sb;

int main(){
	freopen("replace3.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++){
		cin>>sa>>sb;
		for(st=0;st<sa.size();st++){
			if(sa[st]!=sb[st])break;
		}
		for(ed=sa.size();ed>=0;ed--){
			if(sa[ed]!=sb[ed])break;
		}
		int sum=0;
		for(int j=1;j<=n;j++){
			if(ed-st+1>a[j].size()||a[j].size()>sa.size())continue;
			int t=sa.find(a[j]);
			if(t>sa.size())continue;
			sum++;
			for(int k=0;k<a[j].size();k++){
				if(b[j][k]!=sb[k+t]){
					sum--;
					break;
				}
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
