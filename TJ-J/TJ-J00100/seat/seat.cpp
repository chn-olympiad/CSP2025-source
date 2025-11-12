#include<bits/stdc++.h>
using namespace std;
long long s[1005][1005],n,m,l[9999],p=1,h;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>h;
	l[1]=h;
	for(long long i=2;i<(n*m);i++){
		cin>>l[i];
	}
	sort(l+1,l+1+n*m,cmp);
	for(long long i=1;i<=m;i++){
		if(i%2==1){
		    for(long long j=1;j<=n;j++){
				s[i][j]=l[p];
				if(l[p]==h){
					cout<<i<<" "<<j;
				}
				//fclose(stdin);
	            //fclose(stdout);
	            //return 0;
				p++;
			}
		}
		else{
			for(long long j=n;j>=1;j--){
				s[i][j]=l[p];
				if(l[p]==h){
					cout<<i<<" "<<j;
				}
				//fclose(stdin);
               	//fclose(stdout);
	            //return 0;
				p++;
			}
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

