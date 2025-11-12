#include<bits/stdc++.h>
using namespace std;
struct ab{
	string s1,s2;
	int o;
}a[300000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		a[i].o=a[i].s1.size();
	}
	string sp,sq;
	cin>>sp>>sq;
	string sh;
	while(n--){
		for(int i=0;i<sp.size();i++){
			for(int j=1;j<=n;j++){
				if(sp[i]==a[j].s1[0]){
					for(int k=0;k<a[j].o;k++){
						if(sp[i+k]!=a[j].s1[k]){
							ok=1;
							break;
						}
					}
					if(ok==0)sh+=a[i].s2;
				}
				
			}
			sh+=sp[i];
		}
		if(sq==sh)ans++;
		cout<<ans<<endl;
	}
	
	
	return 0;
}

