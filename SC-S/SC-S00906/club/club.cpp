#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,biggest=0,hs,smallest;
};
bool cmp(node a,node b){
	return a.biggest>b.biggest;
}
node JML[100086];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio,cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int A[4]={0};
	    long long ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int j,m,l;
			cin>>j>>m>>l;
			JML[i].biggest=max(max(j,m),max(m,l));
			JML[i].smallest=min(min(j,m),min(m,l));
			if(j==JML[i].biggest)JML[i].hs=1;
			else if(m==JML[i].biggest)JML[i].hs=2;
			else if(l==JML[i].biggest)JML[i].hs=3;
			JML[i].a=j;
			JML[i].b=m;
			JML[i].c=l;
		}
		sort(JML+1,JML+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(A[JML[i].hs]<(n/2)){
				ans+=JML[i].biggest;
				A[JML[i].hs]++;
			}
			else{
				int g=0;
				g+=JML[i].a+JML[i].b+JML[i].c;
				g-=JML[i].biggest;
				g-=JML[i].smallest;
				if(JML[i].a==g){
					if(A[1]<(n/2)){
						A[1]++;
						ans+=g;
					}
					else {
						A[5-JML[i].hs]++;
						ans+=g;
					}
				}
				else if(JML[i].b==g){
					if(A[2]<(n/2)){
						A[2]++;
						ans+=g;
					}
					else {
						A[4-JML[i].hs]++;
						ans+=g;
					}
				}
				else if(JML[i].c==g){
					if(A[3]<(n/2)){
						A[3]++;
						ans+=g;
					}
					else {
						A[3-JML[i].hs]++;
						ans+=g;
					}
				}
			};
		}
		cout<<ans<<"\n";
	}
	return 0;
}