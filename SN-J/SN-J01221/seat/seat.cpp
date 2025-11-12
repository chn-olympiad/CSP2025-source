/*龚逸宸 SN-J01221 西安市曲江第一学校 */
#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105];
bool f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long o=a[1];
	int l=1,h=1;
	sort(a,a+(n*m)+1);
//	for(int i=m*n;i>=1;i--) cout<<a[i];
	for(int i=n*m;i>=1;i--){
		if(a[i]==o){
			cout<<l<<" "<<h;
			return 0;
		}
//		cout<<l<<" "<<h<<endl;
		if(f==0){
			if(h==n){
				l++;
				f=1;
				continue;
			}
			h++;
		}
		else{
			if(h==1){
				l++;
				f=0;
				continue;
			}
			h--;
		}
	}
	return 0;
}
