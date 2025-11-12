#include<bits/stdc++.h>
using namespace std;
int a;
int b[105][3],maxn[105],maxm;
signed main(){
	freopen("club.in","r",stdin)
	freopen("club.out","w",stdout)
	int b[105][3],l1,l2,l3;
	int m1,m2,m3;
	cin>>a;
    for(int i;i<a;i++)
    cin>>b[i][0]>>b[i][1]>>b[i][2];
    for(int i;i<a;i++){
    l1+=b[i][0];
    l2+=b[i][1];
    l3+=b[i][2];
    }
    if(l1>l2&&l1>l3)
    m1=0;
    m2=1;
    m3=2;
    if(l1<l2&&l2>l3)
    m1=1;
    m2=0;
    m3=2;
    if(l3>l2&&l1<l3)
    m1=2;
    m2=1;
    m3=0;
    	int j;
	for(int i;i<a;i++)
	    maxn[i]=max(b[i][m1]-b[i][m2],b[i][m1]-b[i][m3]);
	for(int i;i<a;i++){
		for(int v=i;v<a;v++){
			if(maxn[i]>maxn[v]);
			   j=maxn[i];
			   maxn[i]=maxn[v];
			   maxn[v]=j;
		}
	}
	for(int i;i<a/2;i++)
	    maxm+=maxn[i];
	cout<<maxm;
	return 0;
}
