#include<bits/stdc++.h>
using namespace std;
#define int long long
string aa[200005],bb[200005],c,d,e;
int f,g,h,sum,ans,cnt,summ;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>f>>g;
	for(int i=1;i<=f;i++) cin>>aa[i]>>bb[i];
	for(int j=1;j<=g;j++){
		cin>>c>>d;
		summ=0;
		for(int k=1;k<=f;k++){
			string a=aa[k],b=bb[k];
			h=a.size();
			sum=0,cnt=0;
			for(int i=0;i<c.size();i++){
				if(sum==h) break;
				if(c[i]==a[sum]) sum++;
				else{
					sum=0;
					cnt++;
					i=cnt;
				}
			}
			if(sum==h){
				string ls;
				if(h==c.size()) for(int i=0;i<b.size();i++) ls+=b[i];
				else{
					for(int i=0;i<=cnt;i++) ls+=c[i];
					for(int i=0;i<b.size();i++) ls+=b[i];
					for(int i=cnt+h+1;i<c.size();i++) ls+=c[i];
				}
				int lss=0;
				for(int i=0;i<=ls.size();i++){
					if(ls[i]!=d[i]){
						lss=1;
						break;
					}
				}
				if(lss==0) summ++;
			}
		}
		cout<<summ<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}