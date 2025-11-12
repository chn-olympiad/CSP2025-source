//考号：SN-J01136 姓名：霍启若 学校：蒲城县城南学校 
#include<bits/stdc++.h>
int x,y,r,f,o;
std::vector<int>a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&x,&y);
	for(int i = 0;i < x * y;i++){
		scanf("%d",&o);
		a.push_back(o);
	}
	r = a[0];
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	for(int i = 0;i < x * y;i++) if(a[i] == r) f = i;
	printf("%d ",f / x + 1);
	if((f / x) % 2 == 0) printf("%d",(f % x) + 1);
	else printf("%d",y - (f % x) + 1);
	return 0;
}
