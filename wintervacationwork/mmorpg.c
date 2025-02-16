#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,k;
    
    scanf("%d %d %d",&n,&m,&k);
    char na[n][11];
    char ma[m][11];
    char ka[k][11];
    char nee[n-m+k][11];
    getchar();
    for(int i=0;i<n;i++){
        scanf("%s",na[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%s",ma[i]);
    }
    for(int i=0;i<k;i++){
        scanf("%s",ka[i]);
    }
    int l=0;
    for(int i=0;i<n;i++){
        int ret=1;
        for(int j=0;j<m;j++){
            if(strcmp(na[i],ma[j])==0){
                ret=0;
            }
        }
        if(ret==1){
            strcpy(nee[l++],na[i]);
        }
    }
    for(int i=0;i<k;i++){
        strcpy(nee[l++],ka[i]);
    }
    for(int i=0;i<n-m+k-1;i++){
        for(int j=0;j<n-m+k-i-1;j++){
            if(strcmp(nee[j],nee[j+1])>0){
                char temp[11];
                strcpy(temp,nee[j]);
                strcpy(nee[j],nee[j+1]);
                strcpy(nee[j+1],temp);
            }
        }
    }
    for(int i=0;i<n-m+k;i++){
        printf("%s\n",nee[i]);
    }


    return 0;
}

//above there exceed time limit,below is ok
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 100005
#define MAX_LEN 11
#define HASH_SIZE 100007

// 哈希表节点结构体
typedef struct HashNode {
    char key[MAX_LEN];
    struct HashNode *next;
} HashNode;

// 哈希表
HashNode *hashTable[HASH_SIZE];

// 哈希函数
unsigned int hash(const char *str) {
    unsigned int hashval = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hashval = str[i] + (hashval << 6) + (hashval << 16) - hashval;
    }
    return hashval % HASH_SIZE;
}

// 插入到哈希表
void insert(const char *key) {
    unsigned int index = hash(key);
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->key, key);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// 查找是否在哈希表中
int find(const char *key) {
    unsigned int index = hash(key);
    HashNode *current = hashTable[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// 比较函数，用于 qsort
int compare(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    int n, m, k;
    char na[MAX_N][MAX_LEN];
    char ka[MAX_N][MAX_LEN];
    char new_nodes[MAX_N * 2][MAX_LEN];
    int new_count = 0;

    // 读取 n, m, k
    scanf("%d %d %d", &n, &m, &k);

    // 读取昨天派遣潜艇的节点名字
    for (int i = 0; i < n; i++) {
        scanf("%s", na[i]);
    }

    // 读取所有相连节点已被发现的节点名字，并插入哈希表
    for (int i = 0; i < m; i++) {
        char temp[MAX_LEN];
        scanf("%s", temp);
        insert(temp);
    }

    // 筛选出昨天派遣潜艇但相连节点未全部被发现的节点
    for (int i = 0; i < n; i++) {
        if (!find(na[i])) {
            strcpy(new_nodes[new_count++], na[i]);
        }
    }

    // 读取新发现的节点名字
    for (int i = 0; i < k; i++) {
        scanf("%s", ka[i]);
        strcpy(new_nodes[new_count++], ka[i]);
    }

    // 使用 qsort 函数进行排序
    qsort(new_nodes, new_count, sizeof(new_nodes[0]), compare);

    // 输出排序后的节点名字
    for (int i = 0; i < new_count; i++) {
        puts(new_nodes[i]);
    }

    // 释放哈希表内存
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode *current = hashTable[i];
        while (current != NULL) {
            HashNode *temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
*/