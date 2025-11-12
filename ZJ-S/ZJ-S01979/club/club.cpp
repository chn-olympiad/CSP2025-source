#include<bits/stdc++.h>
using namespace std;
int const N=1e5+5;
int a[N][3];
struct nb{
	int st2,nm;
}m[N];
bool cmp(nb A,nb B){
	if(A.st2==B.st2)
	return A.nm<=B.nm;
	else
	return A.st2<B.st2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
	bool f=1;
		int n;
		cin>>n;
		int x;
		int ans=0;
		int da=-1;
		for(int i=1;i<=n;i++){
			cin>>x;
			da=x;
			m[i].nm=1;
			cin>>x;
			if(x>da){
				m[i].st2=x-da;
				da=x;
				m[i].nm=2;
			}
			else
				m[i].st2=da-x;
			cin>>x;
		if(x!=0) f=0;
			if(x>da){
				m[i].st2=x-da;
				da=x;
				m[i].nm=3;
			}
			else{
				if(da-x<m[i].st2)
					m[i].st2=da-x;
			}
			ans+=da;
		//	printf("%d %d %d\n",m[i].st,m[i].st2,m[i].nm);
		}
	//	sort(m+1,m+n+1,cmp);
		sort(m+1,m+n+1,cmp);
		int l=n/2;
		int q[4][l+1];
		int cl[4]={0,0,0,0};
		for(int i=1;i<=n;i++){
			int t=m[i].nm;
			if(cl[t]<l){
				cl[t]++;
				q[t][cl[t]]=i;
			}
			else{
				int mi=m[1].st2,w=i;
				for(int j=2;j<=cl[t];j++){
					if(m[q[t][j]].st2<=mi){
						mi=m[q[t][j]].st2;
						w=j;
					}
				}
				ans-=mi;
			//	cout<<cl[w]<<" "<<mi<<endl;
			if(w!=i) q[m[i].nm][w]=i;
			//	cout<<cl[w]<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
} 
