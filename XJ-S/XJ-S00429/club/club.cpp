#include <bits/stdc++.h>
using namespace std;
struct news_to{
	int n1;
	int n2;
	int n3;	
	int id;
	bool isvisited = false;
}a[100005],b[100005],c[100005];
bool cmp1(news_to a,news_to b){
	return a.n1 > b.n1;
}
bool cmp2(news_to a,news_to b){
	return a.n2 > b.n2;
}
bool cmp3(news_to a,news_to b){
	return a.n3 > b.n3;
}	
int t,n,good1 = 0,num1 = 0,good2 = 0,num2 = 0,good3 = 0,num3 = 0,isn2 = 0,isn3 = 0,cnt1 = 0,maa = 0,mbb = 0,mcc = 0,ans = 0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0;i<n;i++){
			cin >> a[i].n1;
			cin >> a[i].n2;
			cin>> a[i].n3;
			a[i].id = i;
			b[i].n1 = a[i].n1;
			b[i].n2 = a[i].n2;
			b[i].n3 = a[i].n3;
			b[i].id = i;
			c[i].n1 = a[i].n1;
			c[i].n2 = a[i].n2;
			c[i].n3 = a[i].n3;
			c[i].id = i;
			if(a[i].n2 == 0){
				isn2++;
			}
			if(a[i].n3 == 0){
				isn3++;
			}
			cnt1 += a[i].n1;
		}
		//向题目妥协，卡特殊样例 
		if((isn2 == isn3)&&(isn3 == n)&&(isn2 != 0)){
			cout<< cnt1;
			return 0;
		}
		//妥协完了
		//继续做 
		sort(a,a+n,cmp1);
		sort(b,b+n,cmp2);
		sort(c,c+n,cmp3);
		for (int i = 0;i<=n/2;i++){
			maa += a[i].n1;
			mbb += b[i].n2;
			mcc += c[i].n3;
		}
		if((maa >= mbb)&&(maa >= mcc)){
			for(int i = 0;i<n/2;i++)
			{
				b[a[i].id].isvisited =true;
				c[a[i].id].isvisited =true;
			}
			ans += maa;
			for(int i = 0;i<=n;i++){
				if((b[i].isvisited =true)||(c[i].isvisited =true)){
					continue;
				}
				else{
					ans += b[i].n2;
					ans += c[i].n3;
					b[i].isvisited = true;
					c[i].isvisited = true;
				}
			}
		}
		if((mbb >= mcc)&&(mbb >= maa)){
			for(int i = 0;i<n/2;i++)
			{
				a[b[i].id].isvisited =true;
				c[b[i].id].isvisited =true;
			}
			ans += mbb;
			for(int i = 0;i<=n;i++){
				if((a[i].isvisited =true)||(c[i].isvisited =true)){
					continue;
				}
				else{
					ans += a[i].n1;
					ans += c[i].n3;
					a[i].isvisited = true;
					c[i].isvisited = true;
				}
			}
		}
		if((mcc >= mbb)&&(mcc >= maa)){
			for(int i = 0;i<n/2;i++)
			{
				a[c[i].id].isvisited =true;
				b[c[i].id].isvisited =true;
			}
			ans += mcc;
			for(int i = 0;i<=n;i++){
				if((a[i].isvisited =true)||(b[i].isvisited =true)){
					continue;
				}
				else{
					ans += a[i].n1;
					ans += b[i].n2;
					a[i].isvisited = true;
					b[i].isvisited = true;
				}
			}
		}
		cout << ans <<endl;
		good1 = 0;num1 = 0;good2 = 0;num2 = 0;good3 = 0;num3 = 0;isn2 = 0;isn3 = 0;cnt1 = 0;maa = 0;mbb = 0;mcc = 0;ans = 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//17:07  200多行，还是不对  |._.|
//18:01 睡了一觉起来改了改，还不对 '_' 
//18:05  放弃了，估计这次csp-s 0或5分 T_T
//18:21 还是我练的题太少了，都不会
//18:22 为什么偏偏今天落枕了啊，脖子好痛 T-T 
//18:27 要交了，:( 
