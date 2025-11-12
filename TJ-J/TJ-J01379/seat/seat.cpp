#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int hang,lie;
	int cnt;
	int total=n*m;
	int s[1010];
	int self;
	for(int i=1;i<=total;i++){
		cin>>s[i];
		self=s[1];
	}sort(s,s+total,cmp);
	for(int i=0;i<total;i++){
		if(s[i]==self){
			cnt=i;
			break;	
		}
	}
	if(cnt%n==0){
		if((cnt/n)%2==0){
			hang=1;
			lie=cnt/n;
		}else if((cnt/n)%2!=0){
			hang=n;
			lie=cnt/n;
		}
	}else if(cnt%n!=0){
		if(((cnt/n)+1)%2==0){
			hang=n-cnt%n+1;
			lie=cnt/n+1;
		}else if(((cnt/n)+1)%2!=0){
			hang=cnt%n;
			lie=cnt/n+1;
		}
	}cout<<lie<<" "<<hang;
	return 0;
}

