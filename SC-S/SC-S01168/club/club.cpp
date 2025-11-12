#include<bits/stdc++.h>
using namespace std;
int t,n;
struct sdt{
	int a[3];
	int id;
	string code;
	int cod;
};
sdt arr[500001];
sdt c[4][500001];
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(;t>0;--t){
		scanf("%d",&n);
		c[1][0].cod=0,c[2][0].cod=0,c[3][0].cod=0;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&arr[i].a[0],&arr[i].a[1],&arr[i].a[2]);
			arr[i].id=i;
			if(arr[i].a[0]>=arr[i].a[1]){
				if(arr[i].a[0]>=arr[i].a[2]){
					if(arr[i].a[1]>=arr[i].a[2]){
						arr[i].code="123";
					}else{
						arr[i].code="132";
					}
				}else{
					arr[i].code="312";
				}
			}else{
				if(arr[i].a[1]>=arr[i].a[2]){
					if(arr[i].a[0]>=arr[i].a[2]){
						arr[i].code="213";
					}else{
						arr[i].code="231";
					}
				}else{
					arr[i].code="321";
				}
			}
			c[arr[i].code[0]-'0'][++c[arr[i].code[0]-'0'][0].cod]=arr[i];
		}
		for(int i=1;i<=3;++i){
			for(int x=1;x<=c[i][0].cod;++x){
				for(int j=1;j<c[i][0].cod;++j){
					if(c[i][j].a[i]<c[i][j+1].a[i]){
						swap(c[i][j],c[i][j+1]);
					}
				}
			}
			
		}
		for(int i=1;i<=3;++i){
			if(c[i][0].cod>(n/2)){
				for(int j=n/2+1;j<=c[i][0].cod;++j){
					if(c[c[i][j].code[1]-'0'][0].cod<(n/2)){
						--c[i][0].cod;
						c[c[i][j].code[1]-'0'][++c[c[i][j].code[1]-'0'][0].cod]=c[i][j];
					}else{
						--c[i][0].cod;
						c[c[i][j].code[2]-'0'][++c[c[i][j].code[2]-'0'][0].cod]=c[i][j];
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=3;++i){
			for(int j=1;j<=c[i][0].cod;++j){
				ans+=c[i][j].a[i-1];
			}
		}
		printf("%d\n",ans);
	}

	return 0;
} 