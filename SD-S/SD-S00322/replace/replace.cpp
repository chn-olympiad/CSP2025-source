#include<bits/stdc++.h>
using namespace std;
string a[200005],b[200005];
int c[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		c[i]=a[i].size();
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		int l1=x.size();
		int l2=y.size();
		if(l1!=l2){
			cout<<0<<endl;
			continue;
		}
		int cnt=0;
		for(int i=0;i<l1;i++){
			for(int j=1;j<=n;j++){
				string aa=a[j];
				string bb=b[j];
				string cc=x,dd=y;
				if(x[i]==aa[0]){
					int xx=i+c[j];
					int ans=0;
					for(int k=i;k<xx;k++){
						cc[k]=bb[ans];
						ans++;
					}
				}
				if(cc==dd) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
