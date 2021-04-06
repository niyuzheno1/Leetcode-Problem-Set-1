#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
}
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
template<class T1, class T2, class T3> void sortA_L(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> >*arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
  }
}
struct graph{
  int N;
  int*es;
  int**edge;
  void setEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
  }
  int bipartite(int res[] = NULL, void *mem = wmem){
    int i;
    int j;
    int k;
    int x;
    int*st;
    int sts;
    if(res==NULL){
      walloc1d(&res, N, &mem);
    }
    walloc1d(&st, N, &mem);
    for(i=(0);i<(N);i++){
      res[i] = -1;
    }
    for(i=(0);i<(N);i++){
      if(res[i]==-1){
        res[i] = 0;
        sts = 0;
        st[sts++] = i;
        while(sts){
          x = st[--sts];
          for(j=(0);j<(es[x]);j++){
            k = edge[x][j];
            if(res[k]==-1){
              res[k] = 1 - res[x];
              st[sts++] = k;
            }
            if(res[x] + res[k] != 1){
              return 0;
            }
          }
        }
      }
    }
    return 1;
  }
}
;
#define main dummy_main
int main(){
  wmem = memarr;
  return 0;
}
#undef main
void clear_edge(graph *g){
  int i;
  int N = g->N;
  for(i=(0);i<(N);i++){
    g->es[i] = 0;
  }
}
void add_edge(graph *g, int x, int y){
  int** edge = g->edge;
  int* es = g->es;
  edge[x][es[x]++] = y;
  edge[y][es[y]++] = x;
}
int m;
int v1[200000];
int v2[200000];
int w[200000];
int res[200000];
int solve(int n, vector<vector<int>>& views){
  int i;
  graph g;
  dummy_main();
  int ret = 0;
  m = views.size();
  for(i=(0);i<(m);i++){
    v1[i] = views[i][0];
    v2[i] = views[i][1];
    w[i] = views[i][2];
  }
  sortA_L(m,w,v1,v2);
  g.setEdge(n,m,v1,v2);
  clear_edge(&g);
  for(i=(m)-1;i>=(0);i--){
    add_edge(&g,v1[i], v2[i]);
    if(g.bipartite(res) == 0){
      return w[i];
    }
  }
  return ret;
}
// cLay version 20210103-1

// --- original code ---
// #define main dummy_main
// {}
// #undef main
// 
// void clear_edge(graph *g){
//     int N = g->N;
//     rep(i,N) g->es[i] = 0;
// }
// void add_edge(graph *g, int x, int y){
//     int ** edge = g->edge;
//     int * es = g->es;
//     edge[x][es[x]++] = y;
//     edge[y][es[y]++] = x;
// }
// int m;
// int v1[2d5],v2[2d5], w[2d5], res[2d5];
// 
// int solve(int n, vector<vector<int>>& views) {
//     graph g;
//     dummy_main();
//     int ret = 0;
//     m = views.size();
//     rep(i,m)  v1[i] = views[i][0], v2[i] = views[i][1], w[i] = views[i][2];
//     
//     sortA(m,w,v1,v2);
//     g.setEdge(n,m,v1,v2);
//     clear_edge(&g);
//     rrep(i,m){
//         add_edge(&g,v1[i], v2[i]);
//         if(g.bipartite(res) == 0)  return w[i];
//         
//     }
//     return ret;
// }
// 
// // const int viewsx[][3]= {
// //     {0, 1, 6},
// //     {0, 2, 1},
// //     {0, 3, 4},
// //     {1, 4, 4},
// //     {2, 4, 1},
// //     {3, 4, 3},
// //     {2, 3, 7},
// //     {1, 2, 8},
// //     {1, 3, 8},
// //     {0, 4, 9},
// // };
// // int main(){
// //     int n = 6;
// //     vector<VI> views;
// //     rep(i,10){
// //         vector<int> p1; 
// //         rep(j,3) p1.push_back(viewsx[i][j]);
// //         views.push_back(p1);
// //     }
//     
// //     wt(solve(n,views));
// // }