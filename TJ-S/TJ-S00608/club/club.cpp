#include<bits/stdc++.h>
using namespace std;
long long a,b[1000000],c[1000000],d[1000000],e,r[1000000],t[1000000],l;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>l;
	for(int o=0;o<l;o++){
		e=0;
		cin>>a;
		for(int i=0;i<a;i++){
			cin>>b[i]>>c[i]>>d[i];
			if(c[i]==0&&d[i]==0) {
				r[i]=b[i];
				l=1;
			}
			else if(d[i]==0){
				r[i]=b[i];
				t[i]=c[i];
				l=2;
			}
			e+=max(b[i],max(c[i],d[i]));
		}
		if(a==2){
			cout<<max(max(c[0]+d[1],c[0]+b[1]),max(max(b[0]+c[1],b[0]+d[1]),max(c[0]+b[1],c[0]+d[1])))<<endl;
			continue;
		}
		if(l==1){
			e=0;
			sort(r,r+a);
			for(int i=a-1;i>=a/2-1;i--){
				e+=r[i];
			}
			cout<<e<<endl;
			continue;
		}
		else if(l==2){
			e=0;
		}
		else cout<<e<endl;
	}
	return 0;
}

