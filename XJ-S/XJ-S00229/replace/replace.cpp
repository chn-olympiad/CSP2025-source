#include<bits/stdc++.h>
using namespace std;
struct th{
	int qj,hj,jj;
}arr[200005];
int n,q,ans;
int fz;
string str1,str2;
vector<int> flag[200005];
string s1[200005],s2[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str1>>str2;
		s1[i]=str1;
		s2[i]=str2;
		fz+=str1.size()+str1.size();
		int xb1=str1.find('b'),xb2=str2.find('b');
		arr[i].jj=xb1-xb2+1;
		arr[i].qj=xb1;
		arr[i].hj=str2.size()-xb2-1;
		flag[arr[i].jj].push_back(i);
	}
	if(fz>2000){
		while(q--){
			cin>>str1>>str2;
			ans=0;
			int xb1=str1.find('b'),xb2=str2.find('b'),jj=xb1-xb2+1,qj=xb1,hj=str2.size()-xb2-1;
			for(int v:flag[jj]){
				if(qj>=arr[v].qj&&hj>=arr[v].hj){
					ans++;
				}
			}
			cout<<ans<<'\n';
		}		
	}else{
		while(q--){
			ans=0;
			cin>>str1>>str2;
			for(int i=1;i<=n;i++){
				int xb=str1.find(s1[i]);
				if(xb>=str1.size() || xb<0){
					continue;
				}
				string str3=str1;
				int x=0;
				for(int j=xb;x<s2[i].size();j++){
					str3[j]=s2[i][x];
					x++;
				}
				//cout<<str3<<' ';
				if(str3==str2){
					ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}

