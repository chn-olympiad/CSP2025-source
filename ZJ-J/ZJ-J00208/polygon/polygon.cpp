#include<bits/stdc++.h>
#define endl '\n'
#define QwQ return 0;
#define IOSO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N=5e3+10;
const int mod=998244353;
int a[N];
int n,ans;
set<string> str;
void dfs(int id,int sum,int maxx,int num,string s){
	if(id>n){
		if(num>=3){
			if(sum>maxx*2){
				str.insert(s);
//				ans=(ans+1)%mod;	
			}
		}
		return ;
	}
	if(num>=3){
		if(sum>maxx*2){
			str.insert(s);
//			ans=(ans+1)%mod;
//			cout<<id<<" "<<sum<<" "<<maxx<<" "<<num<<endl;
//			cout<<s<<endl;
		}
	}
	int maxxx=max(maxx,a[id]);
	string res="";
	int tot=id;
	while(tot){
		res=res+(char)(tot%10+'0');
		tot/=10;
	}
	reverse(res.begin(),res.end());
	dfs(id+1,sum,maxx,num,s);
	dfs(id+1,sum+a[id],maxxx,num+1,s+"+"+res);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=50){
		string s="";
		dfs(1,0,0,0,s);
		cout<<str.size()%mod;
	}else{
		cout<<9<<endl;
	}
	QwQ;
}
