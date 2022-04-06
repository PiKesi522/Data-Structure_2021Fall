#include <bits/stdc++.h>
using namespace std;

#define MAXN 50
#define MAXM 100

/**
 * @brief 图中结点的邻接表存储形式
 * 此结构体存储的是邻接表的首部节点
 */
struct L_NODE{
    int ver;    /*!< 结点本身的值 */ 
    L_NODE *link;  /*!< 头部节点所指向的下个节点*/
    L_NODE(int i) : ver(i), link(NULL) {};
    L_NODE(int i, L_NODE *p) : ver(i), link(p) {};
};

/**
 * @brief 图中结点的边
 * 
 */
struct E_NODE{
    int ver1;   /*!< 边的一个点 */ 
    int ver2;   /*!< 边的另一个点 */
    int value;
    E_NODE() : ver1(-1), ver2(-1), value(1){};
    E_NODE(int i1, int i2) : ver1(i1), ver2(i2), value(1){};
    E_NODE(int i1, int i2, int v) : ver1(i1), ver2(i2), value(v){};
};



/*------------------------------ 以下为并查集的内容 ------------------------------*/
/**
 * @brief 并查集结点
 * 
 */
struct NODE{
    int count;  /*!< 子节点个数 */
    int parent; /*!< 父节点 */
    NODE() : count(1), parent(-1){};
    NODE(int i1, int i2) : count(i1), parent(i2){};
};

NODE Set[MAXN]; // 集合的数组

/** 
 * @brief 初始化并查集
 * @param Set 并查集
 * @param n 点的个数
 *
 */
void init_set(NODE Set[], int n){
    for (int i = 0; i < n; i++){
        Set[i].count = 1;
        Set[i].parent = -1;
    }
}

/** 
 * @brief 并查集的并操作
 * @param Set 并查集
 * @param i 要进行并的一个元素,不需要给根节点
 * @param j 要进行并的另一个元素,不需要给根节点
 * @return 合并后的根节点
 */
int union_set(NODE Set[], int i, int j){
    int t = Set[i].count + Set[j].count;
    if(Set[i].count >= Set[j].count){
        Set[j].parent = i;
        Set[i].count = t;
        return i;
    }else{
        Set[i].parent = j;
        Set[j].count = t;
        return j;
    }
}

/** 
 * @brief 并查集元素的查找根节点操作
 * @param Set 并查集
 * @param i 要进行查找的元素
 * @return 所查的元素的根节点
 */
int find_set(NODE Set[], int i){
    while(Set[i].parent >= 0){
        i = Set[i].parent;
    }
    return i;
}
/*------------------------------ 以上为并查集的内容 ------------------------------*/


/*------------------------------ 以下为图遍历的内容 ------------------------------*/
L_NODE *head[MAXN]; // 图的邻接表，作为数组储存结点
bool visit[MAXM];   // 该节点是否被访问过的数组
E_NODE edge[MAXM]; // 图中结点的边

/** 
 * @brief 为具有n个顶点，m条边的无向图建立相应的邻接表
 * @param head      图的邻接表，作为数组储存结点
 * @param n         点的个数
 * @param edge      图中结点的边
 * @param m         边的个数
 *
 */
void Create_adj_list(L_NODE* head[], int n, E_NODE edge[], int m){
    L_NODE *p;
    for (int i = 0; i <= n; i++){
        head[i] = new L_NODE(i);
    }
    for (int i = 0; i < m; i++){
        int u = edge[i].ver1;
        int v = edge[i].ver2;

        // p = new L_NODE(v, head[u]); // 值为v，指向邻接表的头节点
        // head[u] = p;                // 将这个值作为新的邻接表头节点元素
        // p = new L_NODE(u, head[v]);
        // head[v] = p;

        p = new L_NODE(v);
        L_NODE *temp = head[u];
        while(temp->link != NULL)
            temp = temp->link;
        temp->link = p;

        p = new L_NODE(u);
        temp = head[v];
        while(temp->link != NULL)
            temp = temp->link;
        temp->link = p;
    }
}


/** 
 * @brief 初始化visit数组
 * @param n 点的个数
 *
 */
void Init(int n){
    for (int i = 1; i <= n; i++)
        visit[i] = false;
}


/** 
 * @brief 展示邻接表
 * @param head 图的邻接表，作为数组储存结点
 * @param n 点的个数
 *
 */
void Show_the_list(L_NODE *head[], int n){
    for (int i = 1; i <= n; i++){
        cout << head[i]->ver;
        L_NODE *temp = head[i]->link;
        while(temp != NULL){
            cout << " <- " << temp->ver;
            temp = temp->link;
        }
        cout << endl;
    }
}


/** 
 * @brief 广度优先搜索遍历图
 * @param u 搜索位置
 *
 */
void dfs(int u){
    L_NODE *t = head[u];
    visit[u] = true;
    cout << u << " ";
    while(t != NULL){           // 顶点不为空
        if(visit[t->ver] == 0)  // 未被访问过
            dfs(t->ver);        // 递归访问该节点
        t = t->link;
    }
}


/** 
 * @brief 深度优先搜索遍历图
 * @param u 搜索位置
 *
 */
void bfs(int u){
    struct QTYPE{
        int qa = 0;
        int qe = 0;
        int item[MAXN];
    };
    QTYPE queue;

    cout << u << " ";
    visit[u] = true;
    queue.item[0] = u;

    while(queue.qa <= queue.qe){
        int v = queue.item[queue.qa++]; // 取出结点
        L_NODE *t = head[v]; 
        while(t != NULL){   // 结点不为空
            int w = t->ver; 
            if(!visit[w]){
                cout << w << " ";
                visit[w] = true;

                queue.item[++queue.qe] = w; // 进队
            }
            t = t->link; 
        }
    }
}
/*------------------------------ 以上为图遍历的内容 ------------------------------*/


/*------------------------------ 以下为最小生成树的内容 ------------------------------*/
/**
 * @brief Prim算法生成最小树
 * 
 * @param cost 路径开销矩阵
 * @param n 点的个数
 * @param u 从哪一点开始
 */
void Prim(int cost[][MAXN], int n, int u){
    int lowcost[MAXN], closest[MAXN], min, k;
    // lowcost 数组表示以i为终点的所有边的长度。如果为0，则表示此点已经加入生成树之中
    // closest 数组表示从现有的树的顶点出发到没加入树的顶点中最近的顶点。若为0，则表示已经加入生成树
    for (int i = 1; i <= n; i++){
        lowcost[i] = cost[u][i];
        closest[i] = u;
    }

    for (int i = 1; i <= n; i++){
        min = INT_MAX;
        for (int j = 1; j <= n; j++)
            if(lowcost[j] != 0 && lowcost[j] < min){
                min = lowcost[j];
                k = j;
            }

        cout << closest[k] << ' ' << k << ' ' << min;
        lowcost[k] = 0;

        for (int j = 1; j <= n; j++)
            if(cost[k][j] != 0 && cost[k][j] < lowcost[j]){
                lowcost[j] = cost[k][j];
                closest[j] = k;
            }
    }
}

bool cmp(E_NODE A, E_NODE B){return A.value < B.value;}
/**
 * @brief Kruskal算法给出图的最小生成树
 * @param n         点的个数
 * @param edge      图中结点的边
 * @param m         边的个数
 * @return 得到的最小生成树的路径和                                                                                                                                                                                                                                                                                                                                    
 */
int Kruskal(E_NODE edge[], int n, int m){
    E_NODE* InOrder_edge = edge;
    sort(InOrder_edge, InOrder_edge + m, cmp);

    Init(n);
    init_set(Set, n);

    int E_cnt = 0, value = 0, a, b;

    for (int i = 0; i < m, E_cnt < n - 1; i++){
        a = InOrder_edge[i].ver1;
        b = InOrder_edge[i].ver2;
        if(find_set(Set, a) != find_set(Set, b) || (find_set(Set, a) == -1 && find_set(Set, b) == -1)){
            union_set(Set, a, b);
            value += InOrder_edge[i].value;
            E_cnt += 1;
        }
    }
    return value;
}
/*------------------------------ 以上为最小生成树的内容 ------------------------------*/



/*------------------------------ 以下为最短路径的内容 ----------------------------*/
typedef int MAT[MAXN][MAXN];
MAT a, cost, path;

/**
 * @brief Dijkstra算法求出最短路径
 * 
 * @param cost 路径开销矩阵
 * @param n 点的个数
 * @param v 从哪一点出发
 * @param dist 从点v到任一点的路径长度
 * @param pre 从点v到任一点的下一步选择点
 */
void Dijkstra(MAT cost, int n, int v, int dist[], int pre[]){
    bool Record[MAXN] = {false};
    for (int i = 1; i <= n; i++){
        dist[i] = cost[v][i];
        pre[i] = (dist[i] < INT_MAX) ? v : 0;
    }

    Record[v] = true;
    pre[v] = 0;

    for (int i = 1; i <= n; i++){
        int min = INT_MAX;
        int k = 0;
        for (int j = 1; j <= n; j++)
            if(!Record[j])
                if(dist[j] != 0 && dist[j] < min){
                    min = dist[j];
                    k = j;
                }
        if(k == 0)
            continue;
        Record[k] = true;
        for (int j = 1; j <= n; j++){
            if(!Record[j] && cost[k][j] < INT_MAX){
                if(dist[k] + cost[k][j] < dist[j]){
                    dist[j] = dist[k] + cost[k][j];
                    pre[j] = k;
                }
            }
        }
    }
}

/**
 * @brief 寻找最短路径，给出所有节点的最短路径
 * 
 * @param cost 路径开销矩阵
 * @param n 点的个数
 */
void floyd(MAT cost, int n){
    for(int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            a[i][j] = cost[i][j];
            path[i][j] = 0;
        }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if(a[i][k] + a[k][j] < a[i][j]){
                    a[i][j] = a[i][k] + a[k][j];
                    path[i][j] = k;
                }
}

/**
 * @brief 打印最短路径
 * 
 * @param i 从哪一点开始
 * @param j 到哪一点结束
 */
void print_path(int i, int j){
    int k = path[i][j];
    if(k == 0)
        return;
    print_path(i, k);
    cout << k << "-->" << endl;
    print_path(k, j);
}

/**
 * @brief 已知邻接矩阵求传递闭包
 * 
 * @param a 邻接矩阵
 * @param n 点的个数
 */
void TransitiveClosure(MAT a, int n){
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if(a[i][j] == 0)
                    if(a[i][k] + a[k][j] == 2)
                        a[i][j] = 1;
}

/*------------------------------ 以上为最短路径的内容 ----------------------------*/




static int loc = 0;
/** 
 * @brief 初始化构造图，插入边的数据
 * @param edge 插入的边的集合
 * @param i1 插入的边的一个顶点
 * @param i2 插入的边的一个顶点
 *
 */
inline void Add_elem(E_NODE edge[], int i1, int i2){
    edge[loc++] = E_NODE(i1, i2);
}
inline void Add_elem(E_NODE edge[], int i1, int i2, int v){
    edge[loc++] = E_NODE(i1, i2, v);
}

int main(){
    int n = 9, m = 12, u = 1;

    Add_elem(edge, 1, 2);
    Add_elem(edge, 1, 3);
    Add_elem(edge, 1, 4);
    Add_elem(edge, 1, 5);
    Add_elem(edge, 2, 4);
    Add_elem(edge, 2, 5);
    Add_elem(edge, 3, 6);
    Add_elem(edge, 3, 7);
    Add_elem(edge, 4, 5);
    Add_elem(edge, 5, 8);
    Add_elem(edge, 6, 7);
    Add_elem(edge, 6, 9);

    Init(n);

    Create_adj_list(head, n, edge, m);

    Show_the_list(head, n);

    // dfs(u);
    // cout << endl;

    // bfs(u);

    // Kruskal(edge, n, m);

    return 0;
}