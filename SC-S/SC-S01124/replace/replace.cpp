#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+5;
int n,q,cnt,Min=1e8,Max=0;
string a,b,x,y;
map<string,string>m;
//struct v{
//	string x,y;
//}p[N];
void solve(){
	cnt=0;
	string c="",d="";
	cin>>a>>b;
	int A=a.size(),B=b.size();
	a=" "+a;
	b=" "+b;
	if(A!=B){
		cout<<0;
		return;
	}
//	cout<<Min<<" "<<Max<<endl;
	for(int i=Min;i<=Max;i++){
		for(int j=1;j+i<=B+1;j++){
			c=a.substr(j,i);
//			cout<<c<<endl;
			d=" ";
			if(m[c]!=""){
				if(m[c].size()+1==B){
					d+=m[c]; 
				}
				else if(j==1){
					d+=m[c];
					d+=a.substr(j+i,B-j-i+1);
				}
				else if(j+i-1<B){
					d+=a.substr(1,j-1);
					d+=m[c];
					d+=a.substr(j+i,B-j-i+1);
				}
				else{
					d+=a.substr(1,j-1);
					d+=m[c];
				}
			}
			if(d==b){
//				cout<<c<<endl;
				cnt++;
			}
		}
	}
	cout<<cnt;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		m[x]=y;
		if(Min>=x.size())Min=x.size();
		if(Max<=x.size())Max=x.size();
	}
	while(q--){
		solve();
		cout<<"\n";
	}
	return 0;
}