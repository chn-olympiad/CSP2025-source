#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct member{
	int a,b,c,d1;
}a[N];
bool comp(member x,member y){
	if(x.d1 < 0 && y.d1 < 0)
	   return -x.d1 > -y.d1;
	else
	   return x.d1 > y.d1;
}
int n,n1,n2;
long long sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t --){
		cin >> n;
		for(int i = 1;i <= n;i ++){
	   	    scanf("%d",&a[i].a);
	   	    scanf("%d",&a[i].b);
	   	    scanf("%d",&a[i].c);
	   	    a[i].d1 = a[i].b - a[i].a;
	    }
	    sort(a + 1,a + n + 1,comp);
	    for(int i = 1;i <= n;i ++){
	    	if(a[i].d1 > 0){
	    	   if(n2 < n/2){
	    	   	  sum += a[i].b;
	    	   	  n2 ++;
			   }else{
			   	  sum += a[i].a;
			   	  n1 ++;
			   }	
			}
			if(a[i].d1 < 0){
	    	   if(n1 < n/2){
	    	   	  sum += a[i].a;
	    	   	  n1 ++;
			   }else{
			   	  sum += a[i].b;
			   	  n2 ++;
			   }	
			}
			if(a[i].d1 == 0){
				sum += a[i].a;
			}
		}
		cout << sum << '\n';
		sum = 0;
		n1 = 0;
		n2 = 0;
	}
	fclose(stdin);
	fclose(stdout);
   return 0;
}

