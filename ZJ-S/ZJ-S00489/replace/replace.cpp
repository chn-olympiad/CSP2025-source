#include<bits/stdc++.h>
using namespace std;
string a[200005],b[200005],t1,t2,lin1,lin2;
int flag,first,last,len;
int max(int x,int b){
	if(x>=b){
		return x;
	}else{
		return b;
	}
}
int min(int x,int b){
	if(x<=b){
		return x;
	}else{
		return b;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<q;i++){
		flag=-1;
		int num=0;
		cin>>t1>>t2;
		for(int j=0;j<t1.size();j++){
			if(t1[j]!=t2[j] and flag==-1){
				first=j;
				flag=0;
			}else if(t1[j]!=t2[j]){
				last=j;
			}
		}
		for(int j=first;j<=last;j++){
			lin1=lin1+t1[j];
			lin2=lin2+t2[j];
		}
		len=last-first+1;
		for(int j=0;j<n;j++){
			if(a[j].size()<len or a[j].size()>t1.size()){
				continue;
			}else if(a[j].size()==len){	
				if(lin1==a[j] and lin2==b[j]){
					num+=1;
				}
			}else{
				int x=max(first-(a[j].size()-len),0);
				for(x;x<=min(first,t1.size()-a[j].size());x++){
					string zz=lin1,yy=lin2; 
					for(int m=first-1;m>=x;m--){
						zz=t1[m]+zz;
						//cout<<zz<<' '<<x<<endl;
						yy=t2[m]+yy;
					}
					for(int m=last+1;m<=last+(a[j].size()-len)-(first-x);m++){
						zz=zz+t1[m];
						//cout<<zz<<' '<<'n'<<endl;
						yy=yy+t2[m];
					}
					if(zz==a[j] and yy==b[j]){
						num+=1;
					}
				}
			}
		}
		cout<<num<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
