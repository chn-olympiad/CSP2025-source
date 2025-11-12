#include<bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//value
const int inf=2147483647;
const int mod=1e9+7;
const int N=2e6+5;
string s1[N],s2[N];
int l1[N],r1[N];
int n,q;


//function
void solve(){
	string f,t;
	cin>>f>>t;
	int l=inf,r=inf;
	for(int i=0;i<f.length();i++){
		if(l==inf && f[i]!=t[i])l=i;
		else if(l!=inf && r==inf && f[i]==t[i])r=i-1;
	}
	int tmp=f.length()-1;
	r=min(r,tmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(r1[i]-l1[i]!=r-l)continue;
		bool flag=false;
		for(int j=l;j<=r;j++){
			int t1=j-l+l1[i];
			if(s1[i][t1]!=f[j] || s2[i][t1]!=t[j]){
				flag=true;
				break;
			}
		} 
		if(!flag)ans++;
	}
	cout<<ans<<endl;
}


int main(){
	ios::sync_with_stdio(0); 
	cin.tie(); 
	cout.tie();
	
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout);
	
	//ccf我求你了 
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int l=inf,r=inf;
		for(int j=0;j<s1[i].length();j++){
			if(l==inf && s1[i][j]!=s2[i][j])l=j;
			else if(l!=inf && r==inf && s1[i][j]==s2[i][j])r=j-1;
		}
		l1[i]=l;
		r1[i]=min(r,int(s1[i].length()-1));
	}
	while(q--)solve();
	
	//15:57给了2G的空间，感觉数据结构大手子要发力了 
	//16:07好像有个20pts的做法，但感觉很难实现 
	//16:15有一个25pts的hash，但我做不完了。 
	//谢谢你ccf，
	
	return 0;
}

