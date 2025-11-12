#include<bits/stdc++.h>
using namespace std;
int a[10010];
int s[10010];
string p,q,w;
int main(){
	freopen("xor","r",stdin);
	freopen("xor","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s[1]=a[1];
	int A=a[1];
	for(int i=2;i<=n;i++){
		int B=a[i],P=0,Q=0,W=0;
		if(A==0) p[P++]='0';
		else{
			while(A>0){
				int now=A%2;
				p[P++]=(now+'0');
				A/=2;
			}
		}
		if(B==0) q[Q++]='0';
		else{
			while(B>0){
				int now=B%2;
				q[Q++]=(now+'0');
				B/=2;
			}
		}
		if(P<Q){
			int now=Q-P;
			while(now!=0){
				p=p+'0';
				P++;
				now--;
			}
		}else if(Q<P){
			int now=P-Q;
			while(now!=0){
				q=q+'0';
				Q++;
				now--;
			}
		}
		for(int j=max(P,Q)-1;j>=0;j--){
			if(p[j]!=q[j]) w[W++]='0';
			else w[W++]='1';
		}
		int end=0,po=1;
		for(int j=W-1;j>=0;j--){
			end+=(w[j]-'0')*po;
			po*=2;
		}
		s[i]=end;
		A=s[i];
	}
	for(int i=1;i<=n;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}