#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7,L=2007;
int n,q;
string a[N][3];
int f(string s1,string s2,string t1,string t2){
	int ans=0;
	string t11=t1,t22=t2;
	for(int i=0;i<t1.length()-s1.length()+1;i++){
		string t11=t1,t22=t2;
		bool bl=true;
		for(int j=0;j<s1.length();j++){
			if(t11[i+j]!=s1[j]){
//				cout<<i+j<<' '<<t11[i+j]<<' '<<j<<' '<<s1[j]<<"\n";
				bl=false;
				break;
			}
			t11[i+j]=s2[j];
		}
		if(!bl) continue;
//		cout<<t11<<"\n";
//		cout<<t22<<"\n";
		if(t11==t22){
//			cout<<i<<"\n";
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	int sum=0;
	for(int i=1;i<=q;i++){
		string t1,t2;cin>>t1>>t2;
		sum=0;
		for(int j=1;j<=n;j++){
			sum+=f(a[j][0],a[j][1],t1,t2);
		}
		cout<<sum<<"\n";
	}
	return 0;
}
