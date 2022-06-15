//
// 用秩优化后的并查集通用算法模板
// Created by keyanjie on 2022/6/11.
//

class DisjointSetUnion {
private:
    static const int N = 2e5 + 10; // 最大支持长度，需要修改

    int parent[N];
    int rank[N];

    int Find(int x) {
        return (x == parent[x]) ? x : (parent[x] = Find(parent[x]));
    }

    void Union(int x, int y) {
        int X = Find(x), Y = Find(y);
        if (X == Y)
            return;

        if (rank[X] < rank[Y]) {
            parent[X] = Y;
        } else if (rank[X] > rank[Y]) {
            parent[Y] = X;
        } else {
            parent[X] = Y;
            rank[Y]++;
        }
    }

public:
    void proc_command(int n) {
        char cmd;
        int x, y;
        scanf(" %c%d%d\n", &cmd, &x, &y);
        if (cmd == 'D') {
            Union(x, y + n);
            Union(x + n, y);
        } else {
            int X, Y, X_, Y_;
            X = Find(x);
            X_ = Find(x + n);
            Y = Find(y);
            Y_ = Find(y + n);

            if (X == Y_ || X_ == Y) {
                printf("In different gangs.\n");
            } else if (X == Y || X_ == Y_) {
                printf("In the same gang.\n");
            } else {
                printf("Not sure yet.\n");
            }
        }

    }

    void init(int n) {
        memset(rank, 0, sizeof(int) * n * 2 + 1);
        for (int i = 1; i < n * 2 + 1; ++i) {
            parent[i] = i;
        }
    }

    void proc() {
        int n, m;
        scanf("%d%d\n", &n, &m);

        init(n);

        while (m--) {
            proc_command(n);
        }
    }
};