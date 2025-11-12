#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1000]={},s,l=1,h=1,f=0,b=1;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>0;i--){
		if(a[i]==s){
			printf("%d %d",l,h);
			break;
		}
		else{
			if(b){
				if(h==n){
					if(f){
						l++;
						f=0;
						b=0;
					}
					else{
						f=1;
						i++;
					}
				}
				else{
					h++;
				}
			}
			else{
				if(h==1){
					if(f){
						l++;
						f=0;
						b=1;
					}
					else{
						f=1;
						i++;
					}
				}
				else{
						h--;
					}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
