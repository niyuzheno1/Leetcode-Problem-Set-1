#define main dummy_main
{}
#undef main

void clear_edge(graph *g){
    int N = g->N;
    rep(i,N) g->es[i] = 0;
}
void add_edge(graph *g, int x, int y){
    int ** edge = g->edge;
    int * es = g->es;
    edge[x][es[x]++] = y;
    edge[y][es[y]++] = x;
}
int m;
int v1[2d5],v2[2d5], w[2d5], res[2d5];

int solve(int n, vector<vector<int>>& views) {
    graph g;
    dummy_main();
    int ret = 0;
    m = views.size();
    rep(i,m)  v1[i] = views[i][0], v2[i] = views[i][1], w[i] = views[i][2];
    
    sortA(m,w,v1,v2);
    g.setEdge(n,m,v1,v2);
    clear_edge(&g);
    rrep(i,m){
        add_edge(&g,v1[i], v2[i]);
        if(g.bipartite(res) == 0)  return w[i];
        
    }
    return ret;
}

