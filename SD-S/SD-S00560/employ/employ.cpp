#include<bits/stdc++.h>

using namespace std;

#define fst ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define fi first
#define se second

const int N=2e5+10;//×¢ÒâÐÞ¸Ä

int n,m;
string s;
int a[N];
int c[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fst
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) c[i]=i;
	int sum=0;
	do{
		int cnt=0,res=0;
		for(int i=0;i<s.size();i++){
			if(cnt>=a[c[i+1]]) cnt++;
			else{
				if(s[i]=='0') cnt++;
				else res++;
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<c[i]<<' ';
//		}
//		cout<<endl;
//		cout<<res<<endl;
		if(res>=m) sum++;
	}while(next_permutation(c+1,c+1+n));
	cout<<sum<<endl;
	return 0;
}

