#include<bits/stdc++.h>
using namespace std;
struct CL{
	int pep,itt,cll;
}cl[300010];
bool fl[100010];
int flag[5];
bool cmp(CL a,CL b){
	return a.itt>b.itt;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long T;
	cin>>T;
	for(int i=1;i<=T;i++){
		int n;
		long long sum=0;
		cin>>n;
		memset(fl,sizeof(fl),0);
		memset(flag,sizeof(flag),0);
		if(n==2){
			long long a,b,c,d,e,f;
			cin>>a>>b>>c>>d>>e>>f;
			cout<<max(max(a+e,a+f),max(max(b+d,b+f),max(c+d,c+e)))<<'\n';
			continue;
		}
		for(int i=1;i<=3*n;i++){
			cin>>cl[i].itt;
			cl[i].pep=(i-1)/3;
			cl[i].cll=(i%3==0?3:i%3);
		}sort(cl+1,cl+1+3*n,cmp);
		for(int i=1;i<=3*n;i++){
			if(!fl[cl[i].pep]&&flag[cl[i].cll]<n/2){
				fl[cl[i].pep]=1;
				sum+=cl[i].itt;
				flag[cl[i].cll]++; 
			}
		}cout<<sum<<'\n';
		for(int i=1;i<=3*n;i++){
			cl[i].cll=cl[i].itt=cl[i].pep=0;
		}
	}
	return 0;
}