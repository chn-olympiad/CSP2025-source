#include <bits/stdc++.h>
using namespace std;
struct q{
	int a,b,c;
	int dabcmaxn,dabcmaxn1,dabcmaxn2;
	int k;
};
bool cmp(q a,q b){
//int 	maxa=max({a.a,a.b ,a.c });
//int maxb =max({b.a ,b.b ,b.c });
return a.dabcmaxn >b.dabcmaxn  ;

}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t;
cin>>t;
while (t--){

	
	int ans=0;
	int maxn=0;
	q wer[10000+100];
	int n;
	cin>>n;
	int da=n/2,db=n/2,dc=n/2;
	for(int i=1;i<=n;i++){
		cin>>wer[i].a >>wer[i].b >>wer[i].c;
		
	wer[i].	dabcmaxn=max({wer[i].a,wer[i].b ,wer[i].c });	
	wer[i].	dabcmaxn2=min({wer[i].a,wer[i].b ,wer[i].c });
	if(wer[i].a !=wer[i].	dabcmaxn&&wer[i].a !=wer[i].dabcmaxn2)wer[i].dabcmaxn1=wer[i].a;
	if(wer[i].b !=wer[i].	dabcmaxn&&wer[i].b !=wer[i].dabcmaxn2)wer[i].dabcmaxn1=wer[i].b;
	if(wer[i].c !=wer[i].	dabcmaxn&&wer[i].c !=wer[i].dabcmaxn2)wer[i].dabcmaxn1=wer[i].c;
	
	}
	sort(wer+1,wer+1+n,cmp);
	
//	for(int i=1;i<=n;i++){
//		cout<<wer[i].a <<wer[i].b <<wer[i].c <<endl;
//	}
int qx =n/2;
for(int i=1;i<=n ;i++){
	
	if(wer[i].dabcmaxn==wer[i].a){
	if( da==0){
	
	}
	da--;
	ans+=wer[i].dabcmaxn ;
	
	}
//	if(wer[i].dabcmaxn==wer[i].b )da--;
//	if(wer[i].dabcmaxn==wer[i].c )da--;
else if(wer[i].dabcmaxn==wer[i].b&& db!=0){
	db--;
	ans+=wer[i].dabcmaxn ;
	
	}

else if(wer[i].dabcmaxn==wer[i].c&& dc!=0){
	dc--;
	ans+=wer[i].dabcmaxn ;
	
	}

}

cout<<ans<<endl;
}
return 0;
}

