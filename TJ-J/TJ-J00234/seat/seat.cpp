#include <bits/stdc++.h>
using namespace std;
int n, m, r, flag, lie, hang;      //r is a_1; flag表示r的位置; 
int a[105];
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);

  cin >> n >> m;
  for(int i = 1; i <= n * m; i++)
  {
  	cin >> a[i];
  }
  r = a[1];
  sort(a + 1, a + n * m + 1);
  //for(int i = n * m; i > 0; i--) cout << a[i];
  for(int i = n * m; i > 0; i--){
  	flag++;
	if(a[i] == r) break;
  }
  lie = ceil(flag / 1.0 / n);
  if(lie % 2 == 0) hang = n % flag;	
  else if(lie == 1) hang = n - n % flag;
  else hang = n - n % flag + 1;
  printf("%d %d", lie, hang);
  return 0;
}
