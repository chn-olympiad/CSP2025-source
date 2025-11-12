#include<bits/stdc++.h>
#define N 1005
using namespace std;
int a[N],n,p[N],cnt,m;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)p[i]=i;
	do{
		int res=0,tmp=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'&&tmp<a[p[i]])res++;
			else tmp++;
		}
		if(res>=m)cnt++;
	}while(next_permutation(p+1,p+1+n));
	cout<<cnt;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
*/