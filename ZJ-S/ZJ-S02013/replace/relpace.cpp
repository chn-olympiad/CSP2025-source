#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
bool samee(string x,string y){
	int llx=x.size(),lly=y.size();
	if(llx!=lly)return false;
	for(int i=0;i<=llx;i++){
		if(x[i]!=y[i])return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		string t11,t22;
		cin>>t11>>t22;//happy time during the test
		string t1=t11,t2=t22;//disgusting test
		long long ans=0;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		for(int j=1;j<=n;j++){
			int at1=t1.find(s1[j]);
			int at2=t2.find(s2[j]);
			if(at1==-1||at2==-1||at1!=at2||t1.size()!=t2.size())continue;
			//cout<<"  "<<at1<<" "<<at1+s1[j].size()<<"\n";
			for(int k=at1;k<at1+s1[j].size();k++){
				t1[k]=s2[j][k-at1];
			}
			//cout<<" "<<t1<<" "<<t2<<"\n";
			if(samee(t1,t2))ans++;
			t1=t11;
			t2=t22;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
