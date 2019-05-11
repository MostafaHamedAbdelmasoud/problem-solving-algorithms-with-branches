Ash Ketchum is a Pokemon trainer who is on a mission to catch all Pokemons in the world. Fortunately,
he has caught most of them and he needs to collect K more different types of Pokemons to complete
his set.
As you may already know, Ash lives in a 2D grid world. Pokemons spawn at integer coordinates on
this grid. In this world there can be multiple Pokemons of the same type. Remember, Ash needs to
catch K more different types of Pokemons not any K Pokemons.
Ash decided to catch those Pokemons by throwing a big squared net from the sky. A Pokemon
is considered to be caught if the Pokemon lies within the boundaries of the net or even on one of its
edges. Ash wants to find a square that contains those Pokemons where each side of the square is either
parallel to the x-axis or to the y-axis.
Can you help Ash find the minimum side of the square that contains K different types of Pokemons
so that he can buy an appropriate sized net to catch ’em all? Since nets need to always have a positive
area, the side of the square needs to be positive.
Input
Your program will be tested on one or more test cases. The first line of the input will be a single integer
T, the number of test cases (1 ≤ T ≤ 100).
Each test case starts with a line that contains two space separated integers:
• N: Number of Pokemons in the world (2 ≤ N ≤ 1000)
• K: Number of types of Pokemons (2 ≤ K ≤ 100)
Followed by N lines each containing 3 space separated integers:
• X: The x-coordinate of the Pokemon(−1, 00, 000, 000 ≤ X ≤ 1, 00, 000, 000)
• Y : The y-coordinate of the Pokemon (−1, 00, 000, 000 ≤ Y ≤ 1, 00, 000, 000)
• Z: The type of the Pokemon (1 ≤ Z ≤ K)
Output
For each test case, print a single line containing the minimum side of a square that contains K different
types of Pokemons.
Sample Input
2
5 2
0 0 1
0 1 1
0 2 1
2 0 2
2 1 2
3 3
0 0 1
1 1 2
2 2 3
Sample Output
2
2



//it is an annoying problem


solution:

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define X first.first
#define Y first.second
#define T second


const int N = 1e3+5, M = 1e6+6, MOD = 1e9+7, OO = 0x3f3f3f3f;
const double EPS = 1e-7;

int t, n, k;
pair<pair<int, int>, int> P[N];

bool ok(int l){
  for(int i = 0 ; i < n ; ++i){
    int yMin = P[i].Y, yMax = yMin+l;
    queue<int> window;        //Pokemon Index
    int types = 0;
    int freq[102] = {};
    for(int j = 0 ; j < n ; ++j)if(P[j].Y >= yMin && P[j].Y <= yMax){
      int xMin = P[window.front()].X, xMax = xMin+l;
      if(window.empty()){
        window.push(j);
        freq[P[j].T] = types = 1;
      }
      else if(P[j].X <= xMax){
        if(freq[P[j].T] == 0)
          ++types;
        ++freq[P[j].T];
        window.push(j);
      }else{
        --freq[P[window.front()].T];
        if(freq[P[window.front()].T] == 0)
          --types;
        window.pop();
        --j;
      }
      if(types == k)  return 1;
    }
  }
  return 0;
}

int binarySearch(){
  ll lo = 0, hi = 2e9+5, mid;
  while(lo < hi){
    mid = (lo+hi)>>1;
    if(ok(mid))   hi = mid;
    else  lo = mid+1;
  }
  return lo;
}

int main(){
  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &n, &k);
    for(int i = 0 ; i < n ; ++i){
      scanf("%d %d %d", &P[i].X, &P[i].Y, &P[i].T);
    }
    sort(P, P+n);
    printf("%d\n", binarySearch());
  }
  return 0;
}
