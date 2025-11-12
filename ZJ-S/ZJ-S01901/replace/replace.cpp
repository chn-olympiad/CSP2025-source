#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int q,n,a[6][N],b[N],c[N],d[N],f=1;
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		//cout<<s1[0];
		for(int j=0;j<=s1.size()-1;j++){
			if(s1[j]=='b') break;
			a[1][i]++;
		}
		a[2][i]=s1.size()-a[1][i]-1;
		for(int j=0;j<=s2.size()-1;j++){
			if(s2[j]=='b') break;
			a[3][i]++;
		}
		a[4][i]=s2.size()-a[3][i]-1;
		a[5][i]=a[1][i]-a[3][i];
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		x=0,y=0;
		int cnt=0;
		for(int i=0;i<=s1.size()-1;i++){
			if(s1[i]=='b') break;
			x++;
		}
		for(int i=0;i<=s2.size()-1;i++){
			if(s2[i]=='b') break;
			y++;
		}
		for(int j=1;j<=n;j++){
			if(a[5][j]==x-y&&x>=a[1][j]&&(s1.size()-x-1)>=a[2][j]) cnt++;
		}
		cout<<cnt<<'\n';
	}
	return 0;
} 
