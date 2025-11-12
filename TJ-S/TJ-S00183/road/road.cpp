#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0,k=0,s=0,q=0,xi=10,z=0,sh=0;
long long a[1000000],a1[1000000],vo[1000000];
long long c[1000000],po[1000000],zo[1000000];
int main(){
	freopen("road.in",'r',stdin);
	freopen("road.out",'w',stdout);
	cin>>n>>m>>k;
	sh=n-1;
	q=m;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>a1[i]>>vo[i];
		z++;
		zo[z]=vo[i];
		if(vo[i]<xi){
			xi=vo[i];
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++){
			s++;
			cin>>po[s];
		}
		if(c[i]>xi+2){
			s-=m;
			for(int fg=1;fg<=m;fg++){
				s++;
		 		po[s]=10;
		    }
		}
		sort(po+1+s-q,po+s+1);
		for(int j=1;j<s;j++){
			z++;
			zo[z]=po[j]+po[j+1]+c[i];
		}
		q=s;
	}
	s=0;
	sort(zo+1,zo+z+1);
	for(int i=1;i<=sh;i++){
		s+=zo[i];
		cout<<zo[i]<<' ';
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
