#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int minr = 1005;
const int minc = 1005;
int mleft[minr][minc];
int mright[minr][minc];
int mup[minr][minc];
int mdown[minr][minc];
int grid[minr][minc];

int solve() {
    int r, c;
    scanf("%d%d", &r, &c);
    memset(mleft, 0, sizeof(mleft));
    memset(mright, 0, sizeof(mright));
    memset(mup, 0, sizeof(mup));
    memset(mdown, 0, sizeof(mdown));
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        mleft[i][0] = grid[i][0];
        for (int j = 1; j < c; j++) {
            if (grid[i][j]) {
                mleft[i][j] = mleft[i][j-1]+1;
            } else {
                mleft[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < r; i++) {
        mright[i][c-1] = grid[i][c-1];
        for (int j = c-2; j>=0; j--) {
            if (grid[i][j]) {
                mright[i][j] = mright[i][j+1]+1;
            } else {
                mright[i][j] = 0;
            }
        }
    }
    for (int j = 0; j < c; j++) {
        mup[0][j] = grid[0][j];
        for (int i = 1; i < r; i++) {
            if (grid[i][j]) {
                mup[i][j] = mup[i-1][j]+1;
            } else {
                mup[i][j] = 0;
            }
        }
    }
    for (int j = 0; j < c; j++) {
        mdown[r-1][j] = grid[r-1][j];
        for (int i = r-2; i >= 0; i--) {
            if (grid[i][j]) {
                mdown[i][j] = mdown[i+1][j]+1;
            } else {
                mdown[i][j] = 0;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cnt += max(0,min(mright[i][j]-1, mup[i][j]/2-1));
            cnt += max(0,min(mright[i][j]-1, mdown[i][j]/2-1));
            cnt += max(0,min(mleft[i][j]-1, mup[i][j]/2-1));
            cnt += max(0,min(mleft[i][j]-1, mdown[i][j]/2-1));
            cnt += max(0,min(mup[i][j]-1, mleft[i][j]/2-1));
            cnt += max(0,min(mup[i][j]-1, mright[i][j]/2-1));
            cnt += max(0,min(mdown[i][j]-1, mleft[i][j]/2-1));
            cnt += max(0,min(mdown[i][j]-1, mright[i][j]/2-1));
        }
    }
    return cnt;
}


int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        printf("Case #%d: %d\n", i+1, solve());
    }
    return 0;
}