#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int h=0;h<t;h++){
		int n;
		cin >> n;
		int a[100001],b[100001],c[100001];
		int al=0,bl=0,cl=0;
		int ans=0;
		for(int i=0;i<n;i++){
			int a1,b1,c1;
			scanf("%d %d %d",&a1,&b1,&c1);
			int maxx=max(a1,max(b1,c1));
			if(maxx==a1){
				ans+=a1;
				a[al]=a1-max(b1,c1);
				al++;
			} 
			else if(maxx==b1){
				ans+=b1;
				b[bl]=b1-max(a1,c1);
				bl++;
			} 
			else{
				ans+=c1;
				c[cl]=c1-max(a1,b1);
				cl++;
			} 	
		}
		int i=0;
		if(al>n/2){
			sort(a,a+al);
			while(al>n/2){
				ans-=a[i];
				i++;
				al--;
			}
		}
		else if(bl>n/2){
			sort(b,b+bl);
			while(bl>n/2){
				ans-=b[i];
				i++;
				bl--;
			}
		}
		else if(cl>n/2){
			sort(c,c+cl);
			while(cl>n/2){
				ans-=c[i];
				i++;
				cl--;
			}
		}
		cout << ans << endl;	
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
