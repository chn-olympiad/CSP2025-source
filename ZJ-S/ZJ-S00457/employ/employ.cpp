#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int NMX=998244353;
int n,m,t[502],ok1,abd1;
bool td[502];
char jz[502];
int jc(int x){
	if(x==0)return 1;
	return int((long long)x*(long long)jc(x-1)%NMX);
}
int dgf(int k){
	if(k==n)return 0;
	int ansf=0;
	for(int i=0;i<n;i++){
		if(td[i]==0){
			td[i]=1;
			if(abd1>=t[i]||jz[k]=='0'){
				abd1++;
				ansf=(ansf+dgf(k+1))%NMX;
				abd1--;
			}
			else{
				ok1++;
				if(ok1==m)ansf=(ansf+jc(n-k-1))%NMX;
				else ansf=(ansf+dgf(k+1))%NMX;
				ok1--;
			}
			td[i]=0;
		}
	}
	return ansf;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.ans","w",stdout);
	cin>>n>>m;
	cin>>jz;
	for(int i=0;i<n;i++){
		cin>>t[i];
	}
	cout<<dgf(0);
	return 0;
}
