#include<bits/stdc++.h>
using namespace std;
long long X,h,n,q,z;
string a,b,x,s[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(long long i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		if(s[i][1]==s[i][2]){
			i--;
			n--;
		}
	}
	while(q--){
		h=0;
		cin>>a>>b;
		if(a.size()!=b.size()){
			printf("0\n");
		}else{
			z=a.size();
			for(long long i=1;i<=n;i++){
				if((long long)a.find(s[i][1])==-1||(long long)b.find(s[i][2])==-1){
					continue;
				}
				X=s[i][1].size();
				for(long long j=(long long)a.find(s[i][1]);j!=-1;j=(long long)a.find(s[i][1],j+1)){
					x=a;
					x.replace(j,X,s[i][2]);
					if(x==b){
						h++;
					}
				}
			}
			printf("%lld\n",h);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
