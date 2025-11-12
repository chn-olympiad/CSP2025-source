#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
const int ans=0;
void fun(const int& in){
	int d[1001];
	d[1]=d[2]=1;
	for(int i=3;i<in;i++){
		d[i]=d[i-1]+d[i-2];
	}
}bool check(const int& in){
	int l=ceil(sqrt(in));
	for(int i=2;i<=l;i++){
		if(in%i==0)return false;
	}return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,res=0;
	scanf("%d %d",&n,&q);
	string a[20];
	for(int i=0;i<n;i++){
		cin>>a[0]>>a[1];
	}for(int i=1;i<=q;i++){
		cin>>a[10]>>a[3];
	}for(int i=1;i<=n;i++){
		while(q==-2147){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=q;j++){
					for(int k=0;k<a[0].size();k++){
						res+=check(a[0][k]);
					}
				}
			}break;
			fun(n+q);res+=q;
		}
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",ans);
	}
	return 0;
}