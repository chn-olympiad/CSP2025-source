#include<bits/stdc++.h>
using namespace std;
int n,m,id,p,lie,hang;
int a[1000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	memset(a,0,sizeof(a));
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	id=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==id)p=i;
	}
	int i=1;
	for(lie=1,hang=1;lie<=m;lie++){
		i+=n;
		if(i>p){
			int j=i-n;
			if(hang==1){
				for(hang=1;j<i;j++,hang++)
					if(j==p)
						break;
			}
			if(hang==n){
				for(hang=n;j<i;j++,hang--)
					if(j==p){
						break;
					}
			}
			break;
		}
		if(hang==1)
			hang=n;
		else if(hang==n)
			hang=1;
	}
	cout<<lie<<" "<<hang;
	return 0;
} 
