#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int k;
int num[N];
int solve(int a,int b){
	long long sum=1;
	b-=1;
	if(b==0) return a;
	for(int i=1;i<=b;i++){
		sum*=10;
	}
	sum=sum*a;
	return sum;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=N;i++){
		if(s[i]-'0'<0){
			break;
		}
		if(s[i]-'0'>=0){
			if(s[i]>='0' && s[i]<='9'){
				k++;
				num[k]=s[i]-'0';
			}
		}
	}
	long long ans=0;
	int kk=k;
	for(int yy=1;yy<=k;yy++){
		int maxn=0;
		int suo=0;
		for(int i=1;i<=k;i++){
			if(maxn<num[i]){
				maxn=num[i];
				suo=i;
			}
		}
		num[suo]=0;
		ans+=solve(maxn,kk);
		kk--;	
	}
	cout<<ans;
	return 0;
}
