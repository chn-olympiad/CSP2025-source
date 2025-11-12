#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int T,n[N];
struct stu{
	int fi,sc,th,v;
}a[N];
vector<int>cf,cs,ct;
void check(int x){
	int i=1,j=0,k=0 ;
	while(k+j<=x){
		if(k<=x/2){
			if(a[i].fi>=a[i].sc){
				cf[k]=cf[k-1]+a[i].fi;
				k++;
			}else{
				cs[j]=cs[j-1]+a[i].sc;
				j++;
			}
		}
		else{
					cs[j]=cs[j-1]+a[i].sc;
					j++;
		}
		i++;
		n[T]=cf[k]+cs[j];
		cout<<n[T]<<endl;
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--){
		cin>>n[T];
		for(int i=1;i<=n[T];i++){
			cin>>a[i].fi>>a[i].sc>>a[i].th;
		}check(n[T]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}