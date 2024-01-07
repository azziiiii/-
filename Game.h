#ifndef MAIN_CPP_GAME1_H
#define MAIN_CPP_GAME1_H
#include "map.h"
#include <fstream>
#include <cstring>

#define fi first
#define se second

const int N = 310;
const int INF = 0x3f3f3f3f;

class Game
{
private:
    int n, m;               // 城堡数量,道路数量
    int dist[N][N];         // 邻接矩阵
    pair<char, int> vex[N]; // 顶点信息
    char now;
    int heart;
    int wealth;
    int idx;
    char path[N];
    bool vis[N];
public:
    void initdata();
    bool readinfo();
    void mark();
    void showMenu();
    void Start();
    void drawinitalmap();
    void page1();
    void optimalrouteshow();
    void startgame();
    void showrole();
    bool checkwin();
    void showMenu2();
    void Dij(int x);
    void dfs(int u, int fa, int &k, int &w, int &hp, int d[], bool st[], int &ans, char res[], int &resk);
    void outputpath(int end, int pre[]);
};

void Game::initdata()
{
    now = 'A';
    heart = 100;
    wealth = 0;
    idx = 0;
    path[idx++] = now;
    for (int i = 0; i < n; i++)
        vis[i] = false;
    vis[0] = true;
}

bool Game ::readinfo()
{
    ifstream file("C:\\Users\\26798\\Desktop\\11111\\map.txt", ios ::in);
    if (!file.is_open())
    {
        return false;
    }
    file >> n >> m;
    for (int i = 0; i < n; i++)
        file >> vex[i].fi >> vex[i].se;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = INF;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        file >> a >> b >> c;
        dist[a][b] = dist[b][a] = c;
    }
    return true;
}

void Game::mark()
{
    cout << "***********" << endl;
}

void Game::showMenu()
{
    cout << "**************************************************************************" << endl;
    cout << "*                                                                        *" << endl;
    cout << "*                           <夺宝闯关游戏>                               *" << endl;
    cout << "*                            欢迎游玩游戏                                *" << endl;
    cout << "*                                                                        *" << endl;
    cout << "*                             1.开始游戏                                 *" << endl;
    cout << "*                                                                        *" << endl;
    cout << "*                             2.最优路线                                 *" << endl;
    cout << "*                                                                        *" << endl;
    cout << "*                             3.退出游戏                                 *" << endl;
    cout << "*                                                                        *" << endl;
    cout << "**************************************************************************" << endl;
}

void Game::drawinitalmap()
{
    map mmmm1;
    mmmm1.DrawInit();
}

void Game::page1()
{
    drawinitalmap();
    cout << "                                   MAP" << endl;
    cout << endl;
    showMenu();
}

void Game ::Start()
{
//    Widget w(1200, 800);
//    w.init();

    readinfo();
    int choose = 0;
    while (true)
    {
        page1();
        cout << "请输入编号(1 - 3): ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            startgame();
            break;
        case 2:
            optimalrouteshow();
            break;
        case 3:
            cout << "欢迎下次游玩！！！" << endl;
            exit(0);
        default:
            cout << "输入错误,请重新输入" << endl;
            system("cls");
            continue;
        }
        system("pause");
        system("cls");
    }
}

void Game ::showrole()
{
    cout << GREEN1 << "CASTLE : " << now << RESET << "   \n"
         << RED1 << "HP : " << heart << RESET << "   \n"
         << YELLOW1 << "MONEY : " << wealth << RESET << endl;
}

bool Game ::checkwin()
{
    if (heart < 0 || now == 'P')
    {
        if (heart < 0)
            cout << "你失败了, 但请不要气馁!!!" << endl;
        else if (now == 'P')
            cout << "你成功了, 获得了巨大的财富!!!" << endl;
        cout << "本局游戏信息如下:" << endl;
        cout << RED1 << "HP : " << heart << RESET << endl;
        cout << YELLOW1 << "MONEY : " << wealth << RESET << endl;
        cout << GREEN1 << "PATH : ";
        for (int i = 0; i < idx - 1; i++)
        {
            cout << path[i] << " -> ";
        }
        cout << path[idx - 1] << endl;
        cout << RESET << endl;
        cout << "游戏结束!!!, 即将返回主菜单" << endl;
        return true;
    }
    return false;
}

void Game ::startgame()
{
    initdata();
    while (true)
    {
        system("cls");
        drawinitalmap();
        if (checkwin())
            break;
        showrole();
        cout << "你可以到达的城堡是 : ";
        int tmppath[20] = {0};
        int tmpidx = 0;
        int pos = -1;
        for (int i = 0; i < n; i++)
        {
            if (now == vex[i].fi)
            {
                pos = i;
                break;
            }
        }
        for (int i = 0; i < n; i++)
            if (dist[pos][i] != INF)
                tmppath[tmpidx++] = i;
        for (int i = 0; i < tmpidx; i++)
            cout << vex[tmppath[i]].fi << "  ";
        cout << endl;
        char ne;
        cout << "请输入要到达的城堡 : ";
        int nepos;
        int danger;
        while (1)
        {
            cin >> ne;
            bool fl = false;
            for (int i = 0; i < ne; i++)
            {
                if (vex[i].fi == ne)
                    fl = true, nepos = i;
            }
            danger = dist[pos][nepos];
            if (danger == INF)
                fl = false;
            if (!fl)
            {
                cout << "该城堡不可以直接到达, 请重新输入可以到达的城堡 : " << endl;
                continue;
            }
            else
                break;
        }
        if (!vis[nepos])
        {
            wealth += vex[nepos].se;
            vis[nepos] = true;
        }
        if (danger == INF)
        {
            cout << "Error!" << endl;
            exit(0);
        }
        heart -= danger;
        path[idx++] = vex[nepos].fi;
        now = vex[nepos].fi;
    }
}

void Game ::showMenu2()
{
    cout << "**************************************************************************" << endl;
    cout << "*                                                                        *" << endl;
    cout << "*                           <夺宝闯关游戏>                               *" << endl;
    cout << "*                                                                        *" << endl;
    cout << "*                           1.生命值最高路线                             *" << endl;
    cout << "*                                                                        *" << endl;
    cout << "*                           2.财富值最高路线                             *" << endl;
    cout << "*                                                                        *" << endl;
    cout << "*                           3.返回主菜单                                 *" << endl;
    cout << "*                                                                        *" << endl;
    cout << "**************************************************************************" << endl;
}

void Game ::optimalrouteshow()
{
    while (true)
    {
        system("cls");
        drawinitalmap();
        showMenu2();
        int select;
        cout << "请输入菜单选项 : ";
        cin >> select;
        if (select == 1 || select == 2 || select == 3)
        {
            if (select == 1)
            {
                system("cls");
                map mmmm2;
                mmmm2.DrawHighHp();
                showMenu2();
                Dij(0);
            }
            else if (select == 2)
            {
                system("cls");
                map mmmm2;
                mmmm2.DrawHighMoney();
                showMenu2();
                int d[N] = {0};
                bool st[N] = {0};
                char res[N] = {0};
                int k = 0;
                int ttmpw = 0;
                int tmphp = 100;
                int tmpans = 0;
                int tmpresk = 0;
                dfs(0, -1, k, ttmpw, tmphp, d, st, tmpans, res, tmpresk);
                cout << "从起点到终点生命值最高的路径是 " << endl;
                cout << "A->";
                for (int i = 0; i < tmpresk; i++)
                    if (i != tmpresk - 1)
                        cout << res[i] << "->";
                    else
                        cout << res[i] << endl;
            }
            else
            {
                break;
            }
        }
        system("pause");
    }
}

void Game ::outputpath(int end, int pre[])
{
    if (end == -1)
    {
        return;
    }
    outputpath(pre[end], pre);
    if (end == n - 1)
        cout << vex[end].fi;
    else
        cout << vex[end].fi << "->";
}

void Game ::Dij(int x)
{
    int d[N] = {0};
    bool st[N] = {0};
    int pre[N] = {0};
    pre[0] = -1;
    for (int i = 0; i < n; i++)
        d[i] = INF;
    d[x] = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 0; j < n; j++)
            if (!st[j] && (t == -1 || d[t] > d[j]))
                t = j;
        st[t] = true;
        for (int j = 0; j < n; j++)
        {
            if (d[j] > d[t] + dist[t][j])
                d[j] = d[t] + dist[t][j], pre[j] = t;
        }
    }
    if (d[n - 1] == INF)
    {
        cout << "无法活着到达终点!!!" << endl;
    }
    else
    {
        cout << "从起点到终点生命值最高的路径是 : \n";
        outputpath(n - 1, pre);
        cout << endl;
    }
}

void Game ::dfs(int u, int fa, int &k, int &w, int &hp, int path[], bool st[], int &ans, char res[], int &resk)
{
    if (u == n - 1)
    {
        if(hp <= 0)
            return;
        if (ans < w)
        {
            ans = w;
            for (int i = 0; i < k; i++)
                res[i] = vex[path[i]].fi;
            resk = k;
        }
        return;
    }
    if (hp <= 0)
        return;

    for (int i = 0; i < n; i++)
        if (!st[i] && i != fa && dist[u][i] != INF)
        {
            st[i] = true;
            path[k++] = i;
            w += vex[i].se;
            hp -= dist[u][i];
            dfs(i, u, k, w, hp, path, st, ans, res, resk);
            w -= vex[i].se;
            hp += dist[u][i];
            k--;
            st[i] = false;
        }
}


#endif //MAIN_CPP_GAME1_H
