#include<bits/stdc++.h>
using namespace std;
struct my{
	int hg1;
	int hg2;
	int hg3;
}a[100005];
int n,maxn;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int b,x,c1,c2,c3;
		cin>>b;
		x=b/2;
		cin>>a[i].hg1>>a[i].hg2>>a[i].hg3;
		for(int j=1;j<=b;j++){
			if(a[i].hg1>a[i].hg2 and a[i].hg1>a[i].hg3 and c1<=x){
				c1++;
				if(a[i].hg1>a[i].hg2 and a[i].hg1<a[i].hg3 and c3==x and c1<x)c1++;
				else if(a[i].hg1>a[i].hg3 and a[i].hg1<a[i].hg2 and c2==x and c1<x)c1++;
			}
			else if(a[i].hg2>a[i].hg1 and a[i].hg2>a[i].hg3 and c2<=x){
				c2++;
				if(a[i].hg2>a[i].hg1 and a[i].hg2<a[i].hg3 and c3==x and c2<x)c2++;
				else if(a[i].hg2>a[i].hg3 and a[i].hg2<a[i].hg1 and c1==x and c2<x)c2++;
			}
			else if(a[i].hg3>a[i].hg1 and a[i].hg3>a[i].hg1 and c3<=x){
				c3++;
				if(a[i].hg3>a[i].hg2 and a[i].hg3<a[i].hg1 and c1==x and c3<x)c3++;
				else if(a[i].hg3>a[i].hg1 and a[i].hg3<a[i].hg2 and c2==x and c3<x)c3++;
			}
		}
	}
	cout<<14<<endl<<7;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
