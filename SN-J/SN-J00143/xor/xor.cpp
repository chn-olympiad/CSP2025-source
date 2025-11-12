#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;
int n;
queue<long long>gr;
stack<long long>fr;
long long k;
long long orf(long long x,long long y){
	string s="00000000000000000000";
	string t="00000000000000000000";
	while(x!=0){
		for(int i=0;i<=21;i++){
			if(pow(2,i)>x){
				x-=pow(2,i-1);
				s[s.size()-i]='1';
				break;
			}
		}
	}
	while(y!=0){
		for(int i=0;i<=21;i++){
			if(pow(2,i)>y){
				y-=pow(2,i-1);
				t[s.size()-i]='1';
				break;
			}
		}
	}
	long long ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!=t[i])ans+=pow(2,s.size()-i-1);
	}
	return ans;
}
int zc[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cout<<orf(3,3);
	return 0;
	cin>>n>>k;
	if(n==1){
		if(n!=k)cout<<0;
		else if(n==k)cout<<1;
		return 0;
	}
	int cc=0;
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		zc[i]=num;
	}
	if(k==0){
		int pl=0;
		for(int i=1;i<=n;i++){
			if(zc[i]==0)pl++;
		}
		cout<<pl;
		return 0;
	}
	int x=zc[1];
	int mnk=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			x=orf(zc[i],zc[i+j]);
			if(x==k)mnk++;
		}
	}
	cout<<mnk;
	return 0;
}
