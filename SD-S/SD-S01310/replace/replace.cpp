#include <bits/stdc++.h>
using namespace std;
int n,m;
string a[200100],b[200100],c,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(m--){
		cin>>c>>d;
		int t,y,cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i].size()>c.size())continue;
			if(c.size()!=d.size())continue;
			int cc=c.find(a[i]),dd=d.find(b[i]),b=1;
			if(cc!=-1&&dd!=-1){
				if(cc==dd){
					for(int j=0;j<cc;j++){
						if(c[j]!=d[j])b=0;
					}
					for(int j=dd+a[i].size();j<c.size();j++){
						if(c[j]!=d[j])b=0;
					}
					if(b==1){
//						cout<<"owiejgfowefowjigfowjif"<<' ';
//						cout<<a[i]<<endl;
						cnt++;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

