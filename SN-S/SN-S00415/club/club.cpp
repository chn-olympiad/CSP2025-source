#include<bits/stdc++.h>
using namespace std;
int T,n,a[3][100005],maxx[100005],r[3][50005],l[5],cc;
int t (int f){
	a[f][0]=1000000000;  
	int minn=0;
	for(int i=1;i<l[3];i++)if(r[f][minn]>r[f][i])minn=i;  
	for(int i=minn;i<=n;i++)r[f][i]=r[f][i+1];
	l[f]--;
	return 0; 
}
int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		l[1]=0,l[2]=0,l[3]=0,cc=0;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[1][i]>a[2][i]){
				if(a[1][i]>a[3][i])maxx[i]=1;
				else maxx[i]=3;
			}
			else{
				if(a[2][i]>a[3][i])maxx[i]=2;
				else maxx[i]=3;
			}
			if(maxx[i]==1)r[1][l[1]++]=i;
			else if(maxx[i]==2)r[2][l[2]++]=i;
			else r[3][l[3]++]=i;
			while(l[3]>n/2||l[2]>n/2||l[1]>n/2){
				if(l[3]>n/2)t(3);
				if(l[2]>n/2)t(2);
				if(l[1]>n/2)t(1);
			}
		}
		for(int i=0;i<l[1];i++)cc+=a[1][r[1][i]];
		for(int i=0;i<l[2];i++)cc+=a[2][r[2][i]];
		for(int i=0;i<l[3];i++)cc+=a[3][r[3][i]];
		cout<<cc<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

