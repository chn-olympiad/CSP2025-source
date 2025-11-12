#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;
struct Person{
	int v1,v2;
	bool operator< (const Person &x)const{
		return v2>x.v2;
	}
};
vector<Person> clb[3];
int qread(){
	int ret=0;
	char c;
	do{
		c=getchar();
	}while(!isdigit(c));
	do{
		ret=ret*10+c-'0';
		c=getchar();
	}while(isdigit(c));
	return ret;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=qread();
	while(T--){
		n=qread();
		for(int i=0;i<3;i++)clb[i].clear();
		for(int i=1;i<=n;i++){
			int maxi=0,maxn=0,se=0;
			int x;
			for(int j=0;j<3;j++){
				x=qread();
				if(x>maxn)se=maxn,maxi=j,maxn=x;
				else if(x>se)se=x;
			}
			clb[maxi].push_back({maxn,maxn-se});
		}
		long long sum=0;
		for(int i=0;i<3;i++){
			if(clb[i].size()>n/2)sort(clb[i].begin(),clb[i].end());
			for(int j=0;j<clb[i].size();j++){
				if(j<n/2)sum+=clb[i][j].v1;
				else sum+=clb[i][j].v1-clb[i][j].v2;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}