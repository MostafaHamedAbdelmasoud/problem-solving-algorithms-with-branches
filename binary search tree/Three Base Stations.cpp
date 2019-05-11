
The New Vasjuki village is stretched along the motorway and that's why every house on it is characterized by its shift relative to some fixed point — the xi coordinate. The village consists of n houses, the i-th house is located in the point with coordinates of xi.

TELE3, a cellular communication provider planned to locate three base stations so as to provide every house in the village with cellular communication. The base station having power d located in the point t provides with communication all the houses on the segment [t - d, t + d] (including boundaries).

To simplify the integration (and simply not to mix anything up) all the three stations are planned to possess the equal power of d. Which minimal value of d is enough to provide all the houses in the village with cellular communication.

Input
The first line contains an integer n (1 ≤ n ≤ 2·105) which represents the number of houses in the village. The second line contains the coordinates of houses — the sequence x1, x2, ..., xn of integer numbers (1 ≤ xi ≤ 109). It is possible that two or more houses are located on one point. The coordinates are given in a arbitrary order.

Output
Print the required minimal power d. In the second line print three numbers — the possible coordinates of the base stations' location. Print the coordinates with 6 digits after the decimal point. The positions of the stations can be any from 0 to 2·109 inclusively. It is accepted for the base stations to have matching coordinates. If there are many solutions, print any of them.

Examples
Input
4
1 2 3 4
Output
0.500000
1.500000 2.500000 3.500000
Input
3
10 20 30
Output
0
10.000000 20.000000 30.000000
Input
5
10003 10004 10001 10002 1
Output
0.500000
1.000000 10001.500000 10003.500000




solution:



#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 5e5+5, M = 1e6+6, MOD = 1e9+7, OO = 0x3f3f3f3f;
const double EPS = 1e-7;

int n, X[N];


bool ok(double p){
  int nextIndex = 0;
  for(int i = 0 ; i < 3 ; ++i){
    nextIndex = upper_bound(X, X+n, X[nextIndex]+2*p)-X;
    if(nextIndex == n) return 1;
  }
  return 0;
}

double binarySearch(){
  double lo = 0, mid, hi = 1e9;
  int cnt = 100;
  while(cnt--){
    mid = (lo+hi)/2;
    if(ok(mid))   hi = mid;
    else  lo = mid;
  }
  return lo;
}

double SQRT(double n){
  double lo = 0, mid, hi = n;
  int cnt = 100;
  while(cnt--){
    mid = (lo+hi)/2;
    if(mid*mid > n) hi = mid;
    else  lo = mid;
  }
  return lo;
}

int t;

int main(){
  scanf("%d", &n);
  for(int i = 0 ; i < n ; ++i)  scanf("%d", X+i);
  sort(X, X+n);
  double p = binarySearch();
  printf("%lf\n", p);
  int nextIndex = 0;
  for(int i = 0 ; i < 3 ; ++i){
    printf("%lf ", X[nextIndex]+p);
    nextIndex = upper_bound(X, X+n, X[nextIndex]+2*p+EPS)-X;
  }
  return 0;
}
