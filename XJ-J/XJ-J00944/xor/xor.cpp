#include<bits/stdc++.h>
using namespace std;

int n,k,a;
int l[600000];
bool t[600000]

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&l[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int r=0;
			int t1=false;
			for(int e=j;e<=j+i;e++){
				r=r^l[e];
				if(t[e]==true){
					t1=true;
				}
			}
			if(r==k&&t1==false){
				for(int e=j;e<=j+i;e++){
					t[e]=true;
				}
				a++;
			}
		}
	}
	printf("%d",a);
	
	return 0;
}
