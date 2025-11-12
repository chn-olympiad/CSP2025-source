//by snakeMC
//now:PAC  ~10pts
#include<bits/stdc++.h>
using namespace std;
map<string,string> xy;
string can[200010];
int n,q;
int t;
int zc(string s1,string s2,int t){
	int l1=s1.size(),l2=s2.size();
	for(int i=t+1;i<=l1-l2;i++){
		if(s1.substr(i,l2)==s2)return i;
	}
	return -1;
}
int work(string s1,string s2){
	int ans=0;
	string st=s1;
	for(int i=0;i<n;i++){
		t=-1;
		for(int j=0;j<s1.size();j++){
			t=zc(s1,can[i],t);
			if(t==-1)break;
			st.replace(t,can[i].size(),xy[can[i]]);
			if(st==s2){
				ans++;
			}
			st=s1;
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	string t1,t2;
	for(int i=0;i<n;i++){
		cin>>t1>>t2;
		xy[t1]=t2;
		can[i]=t1;
	}
	for(int i=0;i<q;i++){
		cin>>t1>>t2;
		cout<<work(t1,t2)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
